
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
        int n; 
        cin >> n;
        string s;
        cin >> s;
        int a = 0, b = 0;
        bool isAServer = true;
        for(int i = 0; i < n ;i++) {
            if(s[i] == 'A') {
                if(isAServer) {
                    a++;
                } else {
                    isAServer = true;
                } 
            } else {
                if(isAServer) {
                    isAServer = false;
                } else {
                    b++;
                }
            }
        }
        cout << a << " " << b << endl;
    }
    return 0;
}
