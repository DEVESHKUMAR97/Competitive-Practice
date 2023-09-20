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
        if(n == 1) cout << 0;
        else if(n == 2) cout << 0;
        else if(n == 3) cout << 2;
        else {
            int ans = 2;
            n -= 3;
            int pairs = n / 2;
            ans += (pairs*3);
            ans += (n%2 == 1);
            cout << ans;
        }
        cout << endl;
    }
    return 0;
}