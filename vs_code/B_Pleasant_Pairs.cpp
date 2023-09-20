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
        ll n;
        cin >> n;
        vector<ll> a(n);
        unordered_map<ll, ll> mp;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            mp[a[i]] = i+1;
        }

        sort(a.begin(), a.end());

        ll ans = 0;
        for(ll i = 0; i < n; i++) {
            ll b = (2 * n) / a[i];

            ll idx = lower_bound(a.begin(), a.end(), b) - a.begin();

            for(ll j = 0; j <= idx; j++) {
                if(i == j) continue;

                if(mp[a[i]] + mp[a[j]] == a[i] * a[j]) ans++;
            }


        }


        
        cout << ans << endl;

    }
    return 0;
}