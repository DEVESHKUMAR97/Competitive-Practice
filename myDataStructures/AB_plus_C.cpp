
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
        ll x; 
        cin >> x;
        ll a, b, c;
        if(x == 1) {
            cout << -1 << endl;
            continue;
        }

        if(x == 2) a = b = c = 1;
        else {
            ll fakeX = x;
            a = sqrt(fakeX);
            b = a;
            if(a*b == x) {
                b--;
                c = a;
            } else {
                c = x - a*b;
                if(c > a) {
                    b++;
                    c -= a;
                }
            }

        }
        cout << a << " " << b << " " << c << endl;
    }
    return 0;
}
