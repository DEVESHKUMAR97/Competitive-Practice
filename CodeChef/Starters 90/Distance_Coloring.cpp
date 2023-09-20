
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
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // freopen("error.txt", "w", stderr);
    // #endif
 
    int t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        ll ans = 1;
        if(n >= k) {
            
            for(ll i = 1; i <= k; i++) {
                ans = (ans * i) % mod;
            }
        } else {
            for(ll i = k; n > 0; i--, n--) {
                ans = (ans * i) % mod;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
