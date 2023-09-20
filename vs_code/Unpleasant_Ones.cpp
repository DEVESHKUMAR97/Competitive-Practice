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
        int a[n];
        vector<int> evens, odds;

        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(a[i] & 1) odds.push_back(a[i]);
            else evens.push_back(a[i]);
        }

        for(int i = 0; i < evens.size(); i++) cout << evens[i] << " ";
        for(int i = 0; i < odds.size(); i++) cout << odds[i] << " ";
        cout << endl;

    }
    return 0;
}