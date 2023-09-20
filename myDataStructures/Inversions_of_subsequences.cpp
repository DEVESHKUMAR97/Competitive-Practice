
#include<bits/stdc++.h>
#define ll long long int
#define mod 998244353
#define casenum cout << "Case " << ++tt << ": "
#define endl '\n'
using namespace std;

ll mul(ll a, ll b) {
    return ((a%mod) * (b%mod))%mod;
}
 
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
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        if(n == 1) {
            cout << 1 << endl;
            continue;
        }

        vector<int> maxx(n);
        for(int i = 0; i < n; i++) {
            if(i == 0) maxx[i] = a[i];
            else {
                maxx[i] = max(maxx[i-1], a[i]);
            }
        }
        int leftMax, rightMin;
        ll cnt = 0;
        for(int i = n - 1; i >= 0; i--) {
            rightMin = (i == n - 1? INT_MAX : min(rightMin, a[i+1]) );
            leftMax = (i == 0 ? INT_MIN: maxx[i-1]);
            if(leftMax < a[i] && a[i] < rightMin) {
                cnt++;
            }
            // cerr << a[i] << " " << leftMax << " " << rightMin << " " << cnt << endl;
        }
        // cerr << cnt << endl;
        ll ans = 1;
        for(int i = 0; i < cnt; i++) {
            ans = mul(ans, 2);
        }
        if(cnt == n) {
            ans--;
        }
        cout << ans << endl;
    }
    return 0;
}
