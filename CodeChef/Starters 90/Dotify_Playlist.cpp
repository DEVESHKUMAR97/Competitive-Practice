
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
        ll n, k, l;
        cin >> n >> k >> l;

        vector< pair<int, int> > songs(n);
        for(int i = 0; i < n; i++) {
            cin >> songs[i].first;
            cin >> songs[i].second;
        }

        sort(songs.begin(), songs.end(), greater<pair<int, int>> ());

        int cc = 0;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(songs[i].second == l) {
                cc++;
                ans += songs[i].first;
                if(cc == k) break;
            }
        }
        if(cc < k) cout << -1 << endl;
        else cout << ans << endl;
    }
    return 0;
}
