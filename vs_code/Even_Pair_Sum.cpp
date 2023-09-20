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
        ll a, b;
        cin >> a >> b;
        cout << (((a + 1) / 2) * ((b + 1) / 2) + (a / 2) * (b / 2)) << endl;
    }
    return 0;
}