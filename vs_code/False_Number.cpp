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

        int idx = -1;

        for(int i = 0; i < s.length(); i++) {
            if(s[i] != '1') {
                idx = i;
                break;
            }
        }

        if(idx == 0) {
            cout << "1" << s << endl;
        } else {
            for(int i = 0; i < s.length(); i++) {
                if(i == idx) cout << "0";
                cout << s[i];
            }
            cout << endl;
        }
    }
    return 0;
}