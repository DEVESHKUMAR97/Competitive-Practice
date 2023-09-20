#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define casenum cout << "Case " << ++tt << ": "
#define endl '\n'
using namespace std;

void printVector(vector<int>& a) {
    for(int i = 0; i < a.size(); i++) {
        cout << a[i] << ", ";
    }
    cout << endl;
}
 
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
        ll n, m;
        cin >> n >> m;
        ll ans = n * (n+1)/2;
        ll temp;
        ll sum = 0;
        for(int i = 0; i < m; i++) {
            cin >> temp;
            sum += temp;
        }
        cout << (ans - sum) << endl;
    }
    return 0;
}
