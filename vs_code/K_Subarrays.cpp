#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define casenum cout << "Case " << ++tt << ": "
#define endl '\n'
using namespace std;


pair<ll, ll> solve(ll *a, int low, int n) {
    ll rightMaxSum = -1e18;
    ll rightMaxSumStart = 1;
    ll rightSum = 0;
    ll rightSumStartTemp = 1;

    for(int i = low; i < n; i++) {
        rightSum += a[i];

        if(rightSum >= rightMaxSum) {
            rightMaxSum = rightSum;
            rightMaxSumStart = rightSumStartTemp;
        }

        if(rightSum < 0) {
            rightSum = 0;
            rightSumStartTemp = i + 1;
        }
    }

    pair<ll, ll> ans = {rightMaxSum, rightMaxSumStart};
    return ans;
}
 
int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(10);
 
    int t;
    cin >> t;
    while(t--){

        ll n, k;
        cin >> n >> k;
        ll a[n];
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        if(k == 1) {
            ll sum = 0;
            ll maxSum = -1e7;
            for(int i = 0; i < n; i++) {
                sum += a[i];
                maxSum = max(sum, maxSum);
                if(sum < 0) {
                    sum = 0;
                }
            }

            cout << maxSum << endl;
            continue;
        } else if(k == 2) {
            ll ans = -1e18;

            ll leftMaxSum = a[0];
            ll leftTempSum = a[0];
            if(leftTempSum < 0) leftTempSum = 0;


            pair<ll, ll> right = solve(a, 1, n);


            for(int i = 1; i < n; i++) {
                if(i <= right.second) {
                    ans = max(ans, leftMaxSum + 2 * right.first);
                } else {
                    right = solve(a, i, n);
                    ans = max(ans, leftMaxSum + 2 * right.first);
                }

                leftTempSum += a[i];
                if(leftTempSum >= leftMaxSum) {
                    leftMaxSum = leftTempSum;
                }

                if(leftTempSum < 0) leftTempSum = 0;
            }

            cout << ans << endl;
        } else {
            cout << 0 << endl;
        }


        
    }
    return 0;
}