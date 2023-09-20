#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define casenum cout << "Case " << ++tt << ": "
#define endl '\n'
using namespace std;

ll find_next_set_index(vector<ll> &v, ll current) {
    ll index =  upper_bound(v.begin(), v.end(), current) - v.begin();   
    if(index == v.size()) return -1;
    return v[index];
}
 
int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(10);
 
    ll t;
    cin >> t;
    while(t--){
        ll n, x;
        cin >> n >> x;
        ll a[n];
        for(ll i = 0; i < n; i++) cin >> a[i];
        vector< bitset<34> > vec;
        for(ll i = 0; i < n; i++) {
            vec.push_back(a[i]);
        }
        vector< ll > one_at[34];
        for(ll i = 0; i < n; i++) {
            for(ll j = 33; j >= 0; j--) {
                // cout << vec[i][j];
                if(vec[i][j] == 1) {
                    one_at[j].push_back(i);
                } 
            }
            // cout << endl;
        }
        ll pointer = 0, bit_index = 33;
        ll next_set_index;
        while(x > 0 && pointer < n - 1) {
            if(a[pointer] == 0) {
                pointer++;
                bit_index = 33;
                continue;
            }
            while(x > 0 && bit_index >= 0) {
                if(a[pointer] == 0) break;
                if(vec[pointer][bit_index] == 1) {
                    x--;
                    vec[pointer][bit_index] = 0;
                    a[pointer] -= (1ll << bit_index);
                    next_set_index = find_next_set_index(one_at[bit_index], pointer);
                    if(next_set_index == -1) {
                        vec[n-1][bit_index] = 1;
                        a[n-1] += (1ll << bit_index);
                    } else {
                        vec[next_set_index][bit_index] = 0;
                        a[next_set_index] -= (1ll << bit_index);
                    }
                }
                bit_index--;
            }
        }
        if(x % 2 == 1 && n == 2) {
            a[n-2] += 1;
            if(a[n-1] % 2 == 0) {
                a[n-1]++;
            } else {
                a[n-1]--;
            }
        }

        for(ll i = 0; i < n; i++) cout << a[i] << " ";
        cout << endl;

    }
    return 0;
}