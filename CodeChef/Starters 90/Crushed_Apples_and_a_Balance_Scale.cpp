
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
        ll known, target;
        cin >> known >> target;
        bool ans;
        if(target > known) {
            ans = false;
        } else if(target == known) {
            ans = true;
        } else if(known % 2 == 1) {
            ans = false;
        } else {
            ll smallestKnown = known;
            while(smallestKnown % 2 == 0) {
                smallestKnown >>= 1;
            }
            ll times = known / smallestKnown;
            if(target % smallestKnown == 0) {
                ans = true;
            } else {
                ans = false;
            }
        }
        cout << (ans ? "YES" : "NO") << endl;
    }
    return 0;
}
