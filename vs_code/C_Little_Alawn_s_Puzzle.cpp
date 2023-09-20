#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define casenum cout << "Case " << ++tt << ": "
#define endl '\n'
using namespace std;

ll mod_pow(ll x, ll y) {
    if(y == 0) return 1;

    ll ans = 1;
    if(y & 1) ans = (ans * x) % mod;

    ll temp = mod_pow(x, y / 2);
    temp = (temp * temp) % mod;
    return (ans * temp) % mod;
}
 
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
        ll a[n];
        ll b[n];
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for(int i = 0; i < n; i++) {
            cin >> b[i];
        }
        ll temp[n+1];
        ll vis[n+1] = {0};
        for(int i = 0; i < n; i++) {
            temp[a[i]] = b[i];
        }

        ll cnt = 0;
        for(int i = 1; i <= n; i++) {
            int curr = i;
            if(vis[curr] == 0) {
                cnt++;
                while(vis[curr] == 0) {
                    vis[curr] = 1;
                    curr = temp[curr];
                }
            }
        }

        cout << mod_pow(2, cnt) << endl;
        
    }
    return 0;
}