#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define casenum cout << "Case " << ++tt << ": "
#define endl '\n'
using namespace std;

void cummulativeSum(vector<vector<ll>>& A, int n, int m) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(i == 0 && j == 0) {
                continue;
            } else if(i == 0) {
                A[i][j] += A[i][j-1];
            } else if(j == 0) {
                A[i][j] += A[i-1][j];
            } else {
                A[i][j] += (A[i-1][j] + A[i][j-1] - A[i-1][j-1]);
            }
        }
    }
}
void print(vector<vector<ll>>& A, int n, int m) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cerr << A[i][j] << ", ";
        }
        cerr << endl;
    }
}
ll findSum(vector<vector<ll>>& A, int i, int j, int x, int y) {
    ll tSum;
    tSum = A[x][y];
    if(i > 0) {
        tSum -= A[i-1][y];
    }
    if(j > 0) {
        tSum -= A[x][j-1];
    }
    if(i > 0 && j > 0) {
        tSum += A[i-1][j-1];
    }
    return tSum;
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
        ll totalCap = 0;
        vector<vector<ll>> A(n, vector<ll>(m));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> A[i][j];
                totalCap += A[i][j];
            }
        }
        if(totalCap < k+1) {
            cout << -1 << endl;
            continue;
        }

        vector<vector<ll>> ASum = A;

        cummulativeSum(ASum, n, m);
        // print(A, n, m);

        k++;
        ll ans = INT_MAX;
        ll tSum;
        ll tAns;
        int flag;
        int lowX, lowY, highX, highY;
        ll low, high, mid;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(A[i][j] > 0) {
                    low = 0;
                    high = max(n-1, m-1);
                    while(low <= high) {
                        mid = low + (high-low)/2;
                        lowX = max(i - mid, 0ll);
                        lowY = max(j - mid, 0ll);
                        highX = min(i + mid, n-1);
                        highY = min(j + mid, m-1);
                        tSum = findSum(ASum, lowX, lowY, highX, highY);

                        if(tSum>=k) {
                            tAns = mid;
                            high = mid-1;
                        } else {
                            low = mid+1;
                        }

                    }
                    ans = min(ans, tAns);
                }
            }
        }
        cout << ans << endl;

    }
    return 0;
}