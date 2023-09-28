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
 
int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(10);
 
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        string s;
        cin >> s;
        ll ans = 1;
        for(int i = 2; i < n; i += 2) {
            if(s[i-2] == '0' && s[i-1] == '0') {
                if(s[i] == '1') {
                    ans = 0;
                } else {
                    ans = mul(3, ans);
                }

            } else if(s[i-2] == '0' && s[i-1] == '1') {
                if(s[i] == '1') {
                    ans = mul(2, ans);
                } else {
                    // do nothing or multiply by 1
                }
            } else if(s[i-2] == '1' && s[i-1] == '0') {
                if(s[i] == '1') {
                    ans = mul(2, ans);
                } else {
                    // do nothing or multiply by 1
                }
            } else if(s[i-2] == '1' && s[i-1] == '1') {
                if(s[i] == '1') {
                    ans = mul(2, ans);
                } else {
                    // do nothing or multiply by 1
                }
            }
            if(ans == 0) break;
        }
        cout << ans << endl;
        
    }
    return 0;
}