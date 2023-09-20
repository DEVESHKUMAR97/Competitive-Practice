#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define casenum cout << "Case " << ++tt << ": "
#define endl '\n'
using namespace std;

ll bruteForce(ll n, ll m) {
    ll ans = 0;
    for(int a = 1; a < n; a++) {
        for(int b = a + 1; b <= n; b++) {
            if(m % a == (m % b) % a) ans++;
        }
    }
    return ans;
}
 
int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(10);
 
    int t;
    cin >> t;
    while(t--){
        ll n, m;
        cin >> n >> m;
        cout << "BruteForce(" << n << ", " << m << ") = " << bruteForce(n, m) << endl;
        ll ans = n - 1;

        if(m < n) {
            int aPoss = m - 1 - 2 + 1;
            int bPoss = n - m;
            ans += (aPoss * bPoss);
        }

        int minn = min(n, m);
        for(int a = 2; a < n; a++) {
            if(a == m) {
                int temp = n - m;
                ans += (temp * (temp + 1) / 2);
                break;
            }
            if(m % a == 0 && m / a <= minn) ans++;
            ans += (minn / a) - 1;
        }
        cout << ans << endl;
    }
    return 0;
}