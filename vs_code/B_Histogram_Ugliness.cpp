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
        ll a[n];

        // cout << n << endl;

        for(int i = 0;  i < n; i++) {
            cin >> a[i];
        }

        ll ans = 0;

        for(int i = 0; i < n; i++) {
            if(i == 0) {
                if(a[i] > a[i+1]) {
                    ans += (a[i] - a[i+1]);
                    a[i] = a[i+1];
                    ans += a[i];
                } else {
                    ans += a[i];
                }
            } else if(i == n - 1) {
                if(a[i] > a[i-1]) {
                    ans += (a[i] - a[i-1]);
                    a[i] = a[i-1];
                    ans += a[i];
                } else {
                    ans += a[i];
                }
            } else {
                ll mx = max(a[i-1], a[i+1]);
                ll mn = min(a[i-1], a[i+1]);
                if(a[i] > mx) {
                    ans += (a[i] - mx);
                    a[i] = mx;
                    ans += (a[i] - mn);
                } else if(a[i] > mn) {
                    ans += (a[i] - mn);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}