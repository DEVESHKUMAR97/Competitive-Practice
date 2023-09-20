
#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define casenum cout << "Case " << ++tt << ": "
#define endl '\n'
using namespace std;

int minimum(int a1, int a2, int k1, int k2, int n) {
    int maxWithOutKick = a1 * (k1-1) + a2 * (k2-1);
    if(maxWithOutKick >= n) return 0;
    n -= maxWithOutKick;
    return n;
}

int maximum(int a1, int a2, int k1, int k2, int n) {
    if(k1 > k2) {
        int p2Afford = a2 * k2;
        if(p2Afford >= n) {
            return n / k2;
        } else {
            n -= p2Afford;
            return n / k1 + p2Afford / k2;
        }
    } else {
        int p1Afford = a1 * k1;
        if(p1Afford >= n) {
            return n / k1;
        } else {
            n -= p1Afford;
            return n / k2 + p1Afford / k1;
        }
    }
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
 
    int a1, a2;
    int k1, k2;
    int n;
    cin >> a1 >> a2 >> k1 >> k2 >> n;

    cout << minimum(a1, a2, k1, k2, n) << " " << maximum(a1, a2, k1, k2, n);
    
    return 0;
}
