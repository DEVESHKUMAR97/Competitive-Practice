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

        if(n % 2 == 0) {
            for(int i = 1; i <= n; i += 2) {
                cout << i + 1 << " " << i;
            }
        } else {
            for(int i = 1; i <= n - 3; i += 2) {
                cout << i + 1 << " " << i << " ";
            }
            cout << n - 1 << " " << n << " " << n - 2; 
        }
        cout << endl;
    }
    return 0;
}