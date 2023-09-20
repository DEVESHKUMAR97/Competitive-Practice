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
        ll ht[n];
        for(int i = 0; i < n; i++) {
            cin >> ht[i];
        }

        if(n == 2) {
            sort(ht, ht + n);
            cout << ht[0] <<  " " << ht[1] << endl;
        } else {
            sort(ht, ht + n);

            ll ans[n];
            ll idx;
            ll minDiff = 1e10;
            for(int i = n - 2; i >= 0; i--) {
                if(ht[i+1] - ht[i] < minDiff) {
                    minDiff = ht[i+1] - ht[i];
                    idx = i;
                }
            }
            ans[0] = ht[idx];
            ans[n-1] = ht[idx+1];
            int k = 1;
            for(int i = 0; i < n; i++) {
                if(i == idx || i == idx + 1) continue;
                ans[k++] = ht[i];
            }
            



            // ==========================

            if(n == 4) {
                int diff1 = 0;
                for(int i = 0; i < 3; i++) {
                    diff1 += (ans[i] <= ans[i+1]);
                }
                int diff2 = 0;
                int temp = ans[1];
                ans[1] = ans[2];
                ans[2] = temp;
                for(int i = 0; i < 3; i++) {
                    diff2 += (ans[i] <= ans[i+1]);
                }

                if(diff2 < diff1) {
                    temp = ans[1];
                    ans[1] = ans[2];
                    ans[2] = temp;
                }
            } 
            // ====================

            if(ht[1] - ht[0] == minDiff) {
                cout << ht[0] << " ";
                for(int i = 2; i < n; i++) {
                    cout << ht[i] << " ";
                }
                cout << ht[1] << endl;
                continue;
            }
            
            if(ht[n-1] - ht[n-2] == minDiff) {
                cout << ht[n-2] << " ";
                for(int i = 0; i < n-2; i++) {
                    cout << ht[i] << " ";
                }
                cout << ht[n-1] << endl;
                continue;
            }
            for(int i = 0; i < n; i++) {
                cout << ans[i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}