#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define casenum cout << "Case " << ++tt << ": "
#define endl '\n'
using namespace std;

bool isValid(vector<ll>& a, ll y) {
    set<ll> s;
    for(int i = 0; i < a.size(); i++) {
        s.insert(a[i] | y);
        if(s.size() >= 2) return true;
    }
    return false;
}

int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(10);
    int t;
    cin >> t;
    while(t--) {
       ll n, x;
       cin >> n >> x;
       vector<ll> a(n);
       for(int i = 0; i < n; i++) {
        cin >> a[i];
       }

        int diffBit[32] = {0};
        int u, v;
        int lsbu, lsbv;
        int bit;
        for(int i = 0; i < n - 1; i++) {
            u = a[i];
            v = a[i+1];
            bit = 0;
            while(u > 0 || v > 0) {
                lsbu = u & 1;
                lsbv = v & 1;
                if(lsbu != lsbv) {
                    diffBit[bit] = 1;
                }
                bit++;
                u >>=1;
                v >>=1;
            }
        }


        int ans;
        int flag = 0;

        for(int i = 0; i < 32; i++) {
            if(diffBit[i] == 1 && ((x & (1 << i)) == 0)) {
                ans = x;
                flag = 1;
                break;
            }
        }
        if(flag == 0) {
            int diffMinBit = INT_MAX;
            for(int i = 0; i < 32; i++) {
                if(diffBit[i] == 1) {
                    diffMinBit = i;
                    break;
                }
            }
            ans = x;
            ans = ans | ((1<<diffMinBit) - 1);
            ans = ans & (~(1<<diffMinBit));
        }

        cout << ans << endl;
    }

    
    return 0;
}
