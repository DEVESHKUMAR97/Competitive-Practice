#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define casenum cout << "Case " << ++tt << ": "
#define endl '\n'
using namespace std;

int solve(vector<int> &A, int B) {
    sort(A.begin(), A.end());
    set<int> s;
    s.insert(A[0]);
    int ans = 0;
    for(int i = 1; i < A.size(); i++) {
        if(A[i] == A[i-1]) continue;
        
        if(s.find(A[i] ^ B) != s.end()) {
            ans++;
        }
        s.insert(A[i]);
    }
    // cout << s << endl;
    return ans;
}
 
int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(10);

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int b;
    cin >> b;
 
    cout << solve(a, b) << endl;
    return 0;
}