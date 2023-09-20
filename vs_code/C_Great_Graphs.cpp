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
        ll a[n];
        for(int i = 0; i < n; i++) cin >> a[i];

        sort(a, a + n);

        if(n == 1 || n == 2) cout << 0 << endl;
        else {
            ll ans = 0;

            ll d = n - 2 - 1;
            for(int i = 2; i < n; i++) {
                ans += a[i];
                ans += (d * a[n-1+2-i]);
                d -= 2;
            }
            
            cout << -ans << endl;
        }
    }
    return 0;
}