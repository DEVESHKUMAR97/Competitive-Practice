
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
        ll n, q;
        cin >> n >> q;
        vector<ll> arr(n);
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        vector<ll> freq(n, 0);
        ll l, r;
        while(q--) {
            cin >> l >> r;
            l--;
            freq[l]++;
            if(r < n) {
                freq[r]--;
            }
        }

        for(int i = 1; i < n; i++) {
            freq[i] += freq[i-1];
        }

        vector<pair<ll, ll> > freqWithIndex(n);
        for(int i = 0; i < n; i++) {
            freqWithIndex[i] = {freq[i], i};
        }
        sort(freqWithIndex.begin(), freqWithIndex.end());
        sort(arr.begin(), arr.end());

        ll x = 0;
        vector<ll> ans(n);
        for(int i = 0; i < n; i++) {
            ans[freqWithIndex[i].second] = arr[i];
            x += (freqWithIndex[i].first * arr[i]);
        }
        cout << x << endl;

        for(ll val: ans) {
            cout << val << " ";
        }
        cout << endl;



    }
    return 0;
}
