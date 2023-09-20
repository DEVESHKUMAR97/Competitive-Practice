
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
        bool ans;
        if(2*k > n) {
            ans = false;
        } else {
            ll oddCount = (n+1)/2;
            if(oddCount < k) {
                ans = false;
            } else {
                oddCount -= k;
                if(oddCount % 2 == 0) {
                    ans = true;
                } else {
                    ans = false;
                }
            }
            // if(oddCount % k == 0) {
            //     ans = true;
            // } else {
            //     ans = false;
            // }
        }

        cout << (ans ? "YES" : "NO") << endl;
    }
    return 0;
}
