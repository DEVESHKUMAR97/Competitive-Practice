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
        ll n;
        cin >> n;
        ll a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        ll sum = 0;
        ll ans = 0;
        for(int i = 0; i < n; i++){
            ans |= a[i];
            sum += a[i];
            ans |= sum;
        }
        cout << (ans | sum) << endl;
    }
    return 0;
}