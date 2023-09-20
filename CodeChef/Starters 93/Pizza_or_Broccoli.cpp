
#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define casenum cout << "Case " << ++tt << ": "
#define endl '\n'
using namespace std;

void printVector(vector<int>& a) {
    for(int i = 0; i < a.size(); i++) {
        cout << a[i] << ", ";
    }
    cout << endl;
}
 
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
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        vector<int> before(n, 0), after(n, 0);

        for(int i = 0; i < n; i++) {
            if(s[i] == '0') {
                before[i] = 0;
            } else {
                if(i == 0) {
                    before[i] = 1;
                } else {
                    before[i] = before[i-1] + 1;
                }
            }
        }

        for(int i = n - 1; i >= 0; i--) {
            if(s[i] == '0') {
                after[i] = 0;
            } else {
                if(i == n - 1) {
                    after[i] = 1;
                } else {
                    after[i] = after[i+1] + 1;
                }
            }
        }

        // print(before);
        // print(after);

        int ans = 0;
        int prev, next;
        for(int i = 0; i + k - 1 < n; i++) {
            if(i - 1 >= 0) {
                prev = before[i-1];
            } else {
                prev = 0;
            }

            if(i+k<n) {
                next = after[i+k];
            } else {
                next = 0;
            }

            ans = max(ans, prev + next + k);
        }

        cout << ans << endl;
    }
    return 0;
}
