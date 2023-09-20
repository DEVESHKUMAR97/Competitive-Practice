
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
        int w, l;
        cin >> w >> l;

        bool ans;
        if(w % 2 == 0 || l % 2 == 0) {
            ans = true;
        } else {
            ans = false;
        }
        cout << (ans ? "YES" : "NO") << endl;
    }
    return 0;
}
