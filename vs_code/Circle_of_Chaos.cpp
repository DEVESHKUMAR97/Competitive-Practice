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
        int n, m;
        cin >> n >> m;
        int inp;
        int gcd_bhaiya = 0;
        for(int i = 0; i < m; i++) {
            cin >> inp;
            gcd_bhaiya = __gcd(inp, gcd_bhaiya);
        }
        vector<int> vec;
        for(int i = 1; i * i <= gcd_bhaiya; i++) {
            if(gcd_bhaiya % i == 0) {
                vec.push_back(i);
                if(i * i != gcd_bhaiya) {
                    vec.push_back(gcd_bhaiya / i);
                }
            }
        }
        sort(vec.begin(), vec.end());
        int ans;
        for(int i = vec.size() - 1; i >= 0; i--) {
            if(n >= vec[i]) {
                ans = n - vec[i];
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}