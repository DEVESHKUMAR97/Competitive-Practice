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
 
    // int t;
    // cin >> t;
    // while(t--){
        int n, q;
        cin >> n >> q;
        int a[n];
        unordered_map<int, int> ump;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            ump[a[i]] = 1;
        }

        sort(a, a + n);

        // vector<int>::iterator itr;
        int itr;

        while(q--) {
            int x;
            cin >> x; 

            if(ump.find(x) != ump.end()) {
                cout << "0\n";
                continue;
            } 

            itr = upper_bound(a, a + n, x) - a;
            
            int bade = n - itr;

            // cout << bade << endl;
            if(bade % 2 == 0) {
                cout << "POSITIVE\n";
            } else {
                cout << "NEGATIVE\n";
            }

        }
    // }
    return 0;
}