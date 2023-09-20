
#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define casenum cout << "Case " << ++tt << ": "
#define endl '\n'
using namespace std;

// ll myPow(ll x, ll y) {
//     if(y == 0) {
//         return 1;
//     }

//     int ans = pow((x*x) % mod, y / 2);
//     if(y & 1) {
//         ans = (ans * x) % mod;
//     }
//     return ans;
// }
 
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

    vector<ll> pow2(1000000);
    ll ans = 1;
    pow2[0] = 1;
    for(ll i = 1; i <= 1000000; i++) {
        pow2[i] = (2 * pow2[i-1]) % mod;
    }
 
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int temp;
        int evenCount = 0;
        for(int i = 0; i < n; i++) {
            cin >> temp;
            if(temp % 2 == 0) {
                evenCount++;
            }
        }
        ll ans = pow2[evenCount];
        if(evenCount == n) {
            ans = (ans - 1 + mod) % mod;
        }
        cout <<  ans << endl;
    }
    return 0;
}
