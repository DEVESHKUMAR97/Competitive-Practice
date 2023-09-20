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
        int a[3];
        for(int i = 0; i < 3; i++) {
            cin >> a[i];
        }
        sort(a, a + 3);
        int d1 = a[2] - a[1];
        int d2 = a[1] - a[0];

        if(d1 % 2 == 0 && d2 % 2 == 0) {
            cout << (d1/2) + d2 << endl;
        } else cout << -1 << endl;

    }
    return 0;
}
































