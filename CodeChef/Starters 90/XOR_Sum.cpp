
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
        ll l, r;
        cin >> l >> r;

        unordered_set<int> st;

        for(int i = l; i <= r; i++) {
            for(int j = i; j <= r; j++) {
                // cout << i << " " << j << endl;
                if(((i ^ j) == i + j) && i + j > 0) {
                    // cout << "HELo";
                    st.insert(i+j);
                }
            }
        }
        cout << st.size() << endl;
    }
    return 0;
}
