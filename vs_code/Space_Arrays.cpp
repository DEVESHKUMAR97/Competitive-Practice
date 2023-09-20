#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define casenum cout << "Case " << ++tt << ": "
#define endl '\n'
using namespace std;
 
int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(10);
 
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());

        int available_turns = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] <= i + 1) {
                available_turns += i + 1 - a[i];
            } else {
                available_turns = 0;
                break;
            }
        }

        if(available_turns % 2 == 0) {
            cout << "Second\n";
        } else {
            cout << "First\n";
        }
    }
    return 0;
}