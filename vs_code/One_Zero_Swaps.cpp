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
        string s, p;
        cin >> s >> p;
        // cout << s << endl;
        // cout << p << endl;
        int ones1 = 0;
        int ones2 = 0;
        for(char ch : s) {
            ones1 += (ch == '1');
        }
        for(char ch : p) {
            ones2 += (ch == '1');
        }
        if(ones1 == ones2) {
            int flag = 1;
            int val = 0;
            for(int i = 0; i < n; i++) {
                if(s[i] == '1' && p[i] == '0') {
                    val++;
                } else if(s[i] == '0' && p[i] == '1') {
                    val--;
                }
                if(val < 0) {
                    flag = 0;
                    break;
                }
            }
            if(flag == 1)
                cout << "Yes\n";
            else cout << "No\n";

        }
        else cout << "No\n";
    }
    return 0;
}