#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define casenum cout << "Case #" << ++tt << ": "
#define endl '\n'
using namespace std;
 
int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(10);
 
    int t;
    cin >> t;
    int tt = 0;
    while(t--){
        casenum;
        int n, d, c, m;
        cin >> n >> d >> c >> m;
        string s;
        cin >> s;
        int feededUpto = n;
        // cout << n << " " <<  d << " " << c << " " << m << endl;
        // cout << s << endl;
        for(int i = 0; i < n; i++) {
            if(s[i] == 'C') {
                if(c == 0) {
                    feededUpto = i - 1;
                    break;
                }
                c--;
            } else {
                if(d == 0) {
                    feededUpto = i - 1;
                    break;
                }
                d--;
                c += m;
            }
        }
        int ans = 1;
        for(int i = feededUpto + 1; i < n; i++) {
            if(s[i] == 'D') {
                ans = 0;
                break;
            }
        }
        cout << (ans == 0 ? "NO" : "YES") << endl;
    }
    return 0;
}