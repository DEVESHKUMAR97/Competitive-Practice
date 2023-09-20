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
 
    int t;
    cin >> t;
    while(t--){
        ll n, m, k;
        cin >> n >> m >> k;
        vector<ll> A(n);
        vector<ll> B(m);

        ll sumA = 0, sumB = 0;
        for(int i = 0; i < n; i++) cin >> A[i], sumA += A[i];
        for(int i = 0; i < m; i++) cin >> B[i], sumB += B[i];
        // cout << "=====" << sumA << endl;
        // cout << "=====" << sumB << endl;

        ll req = m * sumA - n * sumB;
        ll ans  = 0;
        if(req <= 0) {
            req = -req;
            req++;
            // cout << "req =>" << req << endl;
            ll gainByB = sumA - n;
            ll gainByA = m*k - sumB;
            ll gain = max(gainByB, gainByA);
            if(gain <= 0) ans = -1;
            else {
                ans = ceil(req*1.0/gain);
            }
        }
        cout << ans << endl;
        


    }
    return 0;
}
