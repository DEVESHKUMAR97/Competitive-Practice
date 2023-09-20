#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define casenum cout << "Case " << ++tt << ": "
#define endl '\n'
using namespace std;


int dp[101][50001];
int a[102];
int n;
/// minimum subset sum difference
bool isSubsetSum(int index, int sum) {
    if(sum == 0) {
        return true;
    }
    if(index == n || sum < 0) {
        return false;
    }

    if(dp[index][sum] != -1) return dp[index][sum];


    return dp[index][sum] = isSubsetSum(index + 1, sum - a[index]) || isSubsetSum(index + 1, sum);
}

int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif
    cout<<fixed<<setprecision(10);

    int t;
    cin >> t;
    while(t--) {
        cin >> n;

        int sum = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }

        memset(dp, -1, sizeof(dp));

        for(int i = sum / 2; i >= 0; i--) {
            if(isSubsetSum(0, i)) {
                cout << sum - 2 * i << endl;
                break;
            }
        }

    }
    return 0;
}  

// Problem link : https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=503
































