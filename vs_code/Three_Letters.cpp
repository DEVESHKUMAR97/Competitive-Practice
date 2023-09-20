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
        int freq[26] = {0};
        for(char ch : s) {
            freq[ch - 'a']++;
        }
        int pairs = 0;
        int odds = 0;
        for(int i = 0; i < 26; i++) {
            pairs += (freq[i] / 2);
            odds += (freq[i] % 2);
        }
        int ans = 0;
        if(odds >= pairs) {
            cout << pairs << endl;
        } else {
            ans += odds;
            pairs -= odds;
            ans += ((pairs / 3) * 2);
            ans += (pairs % 3 == 2);
            cout << ans << endl;
        }
    }
    return 0;
}