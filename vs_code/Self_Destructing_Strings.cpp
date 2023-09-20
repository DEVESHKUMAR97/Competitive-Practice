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
        string s;
        cin >> s;
        int ones = 0;
        for(char ch : s) {
            if(ch == '1') ones++;
        }
        if(s.length() % 2 == 0 && ones > 0 && ones < s.length()) {
            int half = (s.length() / 2);
            int ans = abs(half - ones);
            cout << ans << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}