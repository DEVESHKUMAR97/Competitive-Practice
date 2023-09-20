
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
        int n; cin >> n;
        string s;
        cin >> s;
        int ans;

        unordered_map<char, int> freq;
        for(char ch: s) {
            freq[ch]++;
        }
        if(n % 2 == 0) {

            int isOdd = false;
            for(auto e: freq) {
                if(e.second % 2 == 1) {
                    isOdd = true;
                    break;
                }
            }
            if(isOdd) ans = 0;
            else ans = 1;

        } else {
            int oddCount = 0;
            for(auto e: freq) {
                if(e.second % 2 == 1) {
                    oddCount++;
                    if(oddCount > 1) break;
                }
            }
            if(oddCount == 2) ans = 0;
            else {
                if(freq.size() == 1) {
                    ans = 2;
                } else {
                    ans = 1;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
