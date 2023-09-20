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
        ll mx, mn;
        cin >> mx >> mn;
        cout << (mx - mn) * 2 << endl;

        for(int i = mx; i > mn; i--) {
            cout << i << " ";
        }
        for(int i = mn; i < mx; i++) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}