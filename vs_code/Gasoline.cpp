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
        ll f[n], c[n];
        ll zero_grp = 0;
        ll temp = 0;
        for(int i = 0; i < n; i++) {
            cin >> f[i];
            if(f[i] == 0) {
                temp++;
            } else {
                temp = 0;
            }
            zero_grp = max(temp, zero_grp);
        }
        for(int j = 0; j < n; j++) {
            cin >> c[j];
        }

        if(n == 1) {
            cout << c[0] << endl;
            continue;
        }

        ll ans = 1e9 + 1;
        for(int i = 0; i < n; i++) {
            if(f[i] > zero_grp && ans > c[i]){
                ans = c[i];
            }
        }
        cout << ans * (zero_grp + 1) << endl;


    }
    return 0;
}