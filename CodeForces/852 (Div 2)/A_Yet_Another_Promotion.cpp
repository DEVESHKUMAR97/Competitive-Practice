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
        ll a, b;
        cin >> a >> b;
        ll n, m;
        cin >> n >> m;

        if((m + 1) * b <= m * a) {
            cout << n * b << endl;
        } else {
            ll temp = n / (m + 1);
            ll ans = temp * m * a;
            ll left = n - ((m + 1) * temp);
            if (left * a <= left * b) {
                ans += left * a;
            } else {
                ans += left * b;
            }
            cout << ans << endl;
        }
    }
    return 0;
}