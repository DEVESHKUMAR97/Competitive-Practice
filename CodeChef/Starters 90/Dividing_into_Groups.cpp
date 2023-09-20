
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
        ll n, k;
        cin >> n >> k; 
        vector<ll> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        if(n < k) {
            cout << 0 << endl;
            continue;
        }

        sort(a.begin(), a.end(), greater<ll>());

        priority_queue<ll, vector<ll>, greater<int>> minPQ;

        int i;
          ll ans = 0;
                  ll currAns = 0;

        for(i = 0; i < n; ) {
            if(minPQ.size() < k) {
                minPQ.push(a[i]);
                i++;
            } else {
                currAns += minPQ.top();
                minPQ.pop();

                //pop
                while(minPQ.size() > 0 && minPQ.top() - currAns <= 0) {
                    minPQ.pop();
                }

                if(minPQ.size() == 0) {
                    ans += currAns;
                    currAns = 0;
                }
            }
        }



      



        // ll cap;

        // ll cc = 0;



        // for(; i < n;) {
        //     cap = minPQ.top(); minPQ.pop();
        //     cc = 0;
        //     while(i < n) {
        //         if(cc + a[i] <= cap) {
        //             cc +=a[i];
        //             i++;
        //         } else {
        //             ll take = cap - cc;
        //             cc += take;
        //             a[i] -= take;
        //         }
                
        //     }
        //     currAns += cc;

        //     while(minPQ.size() > 0 && minPQ.top() == currAns) {
        //         minPQ.pop();
        //     }



        //     if(i == n) break;
        // }

        ans += currAns;
        cout << ans << endl;
    }
    return 0;
}
