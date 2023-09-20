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
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int ans = INT_MAX;
        for(int i = 0; i < n; i++) {
            if(i == 0) {
                ans = min(ans, abs(a[i] - a[i+1]));
            } else if(i == n-1) {
                ans = min(ans, abs(a[i]-a[i-1]));
            } else {
                ans = min(ans, max(abs(a[i]-a[i-1]), abs(a[i]-a[i+1])));
            }
        }
        cout << ans << endl;
    }

    
    return 0;
}
