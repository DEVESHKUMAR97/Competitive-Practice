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
        if(n & 1) {
            cout << "Yes\n";
            n *= 2;
            int j = n;
            for(int i = 1; i <= n / 2;) {
                cout << i << " " << j << endl;
                i++;
                j -= 2;
                if(j <= n / 2) {
                    j = n - 1;
                }
            }
        } else {
            cout << "No\n";
        }
    }
    return 0;
}