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
        int n; cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        int runs = 0;
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            runs += a[i];
            if(i + 1 == runs) cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}