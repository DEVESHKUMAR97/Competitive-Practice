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
        int a[n];
        for(int i = 0; i < n; i++) cin >> a[i];
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(i == n - 1) {
                ans++;
            } else if(a[i] != a[i+1]) {
                ans++;
            } else {
                i++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}