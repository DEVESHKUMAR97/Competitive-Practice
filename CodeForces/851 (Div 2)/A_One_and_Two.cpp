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
        int twos = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] == 2) twos++;
        }
        if(twos % 2 != 0) {
            cout << -1 << endl;
        } else {
            int cnt = 0;
            for(int i = 0; i < n; i++) {
                if(a[i] == 2) {
                    cnt++;
                }
                if(cnt == twos / 2) {
                    cout << i + 1<< endl;
                    break;
                }
            }
        }
    }
    return 0;
}