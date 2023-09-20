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

        if(n & 1) {
            int ones = 0;
            for(int i = 0; i < s.length(); i++) {
                if(s[i] == '1') {
                    ones++;
                }
            }

            cout << min(ones - 1, n - ones) << endl;
            continue;
        }

        
    }
    return 0;
}