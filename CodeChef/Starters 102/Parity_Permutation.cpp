#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define casenum cout << "Case " << ++tt << ": "
#define endl '\n'
using namespace std;

template <typename T>
void printVector(vector<T>& a) {
    for(int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

template <typename T>
void printMap(map<T, T>& mp) {
    for(auto& e: mp) {
        cout << e.first << " => " << e.second << endl;
    }
}
ll mul(ll a, ll b) {
    return ((a%mod) * (b%mod)) %mod;
}

const int maxN = (int)(1e5 + 1);
ll fact[maxN];
 
int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(10);

    fact[0] = 1;
    for(int i = 1; i <= maxN; i++) {
        fact[i] = mul(fact[i-1], i);
    }
 
    int t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);
        ll odds = 0, evens = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(a[i] & 1) {
                odds++;
            } else {
                evens++;
            }
        }

        ll ans = 0;

        if(k == 0) {
            if(odds == n || evens == n) {
                ans = fact[n];
            }
        } else {
            if(n & 1) {
                if(odds == evens - 1 || odds == evens + 1) {
                    ans = mul(fact[odds], fact[evens]);
                }

            } else {
                if(odds == evens) {
                    ans = mul(mul(fact[odds], fact[evens]), 2);
                }
            }//jdjslkjlkds
        }

        cout << ans << endl;
    }
    return 0;
}