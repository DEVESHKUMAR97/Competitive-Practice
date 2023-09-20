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
        int n, k;
        cin >> n >> k;
        cout << k / 2 + (n - k) << endl;
        for(int i = k + 1; i <= n; i++) {
            cout << i << " ";
        }
        for(int i = (k+1) / 2; i < k; i++) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}