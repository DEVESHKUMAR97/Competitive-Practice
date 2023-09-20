#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define casenum cout << "Case " << ++tt << ": "
#define endl '\n'
using namespace std;

ll mod_exp(int x, int y) {
    if(y == 0) return 1;

    ll temp = mod_exp(x, y / 2);
    temp = (temp * temp) % mod;
    if(y & 1) return (x * temp) % mod;
    return temp;
}
 
int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(10);
 
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;

        cout << mod_exp(2, n - 1) << endl;
    }
    return 0;
}