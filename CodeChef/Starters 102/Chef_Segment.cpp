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
const ll maxA = (ll)(1e5);
// vector<int> multiples[maxA + 1];
 
// // Calculate all
// // divisors of number
// void sieve()
// {
//     for (int i = 1; i <= maxA; ++i) {
//         for (int j = i; j <= maxA; j += i)
//             multiples[i].push_back(j);
//     }
// }
 
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
        vector<ll> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

       

        sort(a.begin(), a.end());

        vector<unordered_set<ll> > dp;
        dp.push_back({});
        dp.push_back({a[n-1]});

        ll ans = 1*a[n-1];
        for(int i = n - 2; i >= 0; i--) {
            bool flag = false;
            for(ll bucketIndex = dp.size() - 1; bucketIndex >= 0; bucketIndex--) {
                ll multiple = a[i];
                ll k = 1;
                while(multiple <= maxA) {
                    if(dp[bucketIndex].count(multiple)) {
                        if(bucketIndex == dp.size() - 1) {
                            dp.push_back({a[i]});
                            ans = max(ans, a[i] * (bucketIndex+1));
                        } else {
                            dp[bucketIndex+1].insert(a[i]);
                            ans = max(ans, a[i] * (bucketIndex+1));

                        }
                        flag = true;
                        break;
                    }
                    k++;
                    multiple = a[i] *k;
                }
                if(flag) break;
            }
            if(flag == false) {
                dp[1].insert(a[i]);
                ans = max(ans, a[i]);
            }
        }
        cout << ans << endl;
        
    }
    return 0;
}