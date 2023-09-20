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
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;

        int dist = abs(a-c) + abs(b - d);
        k -= dist;
        cout << (k % 2 == 0 && k >= 0 ? "YES" : "NO") << endl;
    }
    return 0;
}