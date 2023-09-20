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
    
    ll n;
    cin >> n;
    bitset<200005> not_leaf;
    for(int i = 2; i <= n; i++){
        int u;
        cin >> u;
        not_leaf[u] = 1;
    }

    ll leafs = 0;
    long double sum = 0;
    for(int i = 1; i <= n; i++){
        ll a;
        cin >> a;
        sum += a;
        leafs += (not_leaf[i] == 0);
    }
    cout << (ll)ceil(sum/leafs) << endl;;
    return 0;
}