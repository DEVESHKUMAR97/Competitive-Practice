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
        string s;
        cin >> s;

        int ans = 0;
        int consecutive1 = 1;
        for(int i = 0; i < n; i++){
            if(s[(i - 1 + n)%n] == '1' && s[i] == '1'){
                consecutive1++;
            } else {
                ans += consecutive1 - 1;
                consecutive1 = 1;
            }
        }
        ans += consecutive1 - 1;

        // int ans2 = 0;
        // consecutive1 = 1;
        // for(int i = 1; i < n; i++){
        //     if(s[i - 1] == '0' && s[i] == '0'){
        //         consecutive1++;
        //     } else {
        //         ans2 += consecutive1 - 1;
        //         consecutive1 = 1;
        //     }
        // }
        // ans2 += consecutive1 - 1;
        // cout << min(ans, ans2) << endl;
        cout << ans << endl;
    }
    return 0;
}