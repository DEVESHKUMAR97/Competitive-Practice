
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
        vector<int> a(n);
        int sum = 0; int minn = INT_MAX;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
            minn = min(a[i], minn);
        }
        int isChef = 0;
        if( n % 2 == 1) {
            if(sum % 2 == 1) {
                isChef = 1;
            } else {
                isChef = 0;
            }
        } else {
            if(sum % 2 == 0) {
                isChef = 1;
            } else {
                isChef = 0;
            }
        }
        cout << (isChef == 1 ? "CHEF" : "CHEFINA") << endl;

    }
    return 0;
}
