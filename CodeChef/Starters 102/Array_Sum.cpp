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
 
int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(10);
 
    int t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;

        ll sum = (n/2) * 3;
        ll maxSum = (n/2) * (ll)(1e5) + (n/2) * ((ll)1e5-1);
        if(k < sum || k > maxSum) {
            cout << -1 << endl;
            continue;
        }
        k -= sum;
        if(k % 2 != 0) {
            cout << -1 << endl;
            continue;
        }

        vector<ll> a(n);
        for(int i = 0; i < n; i++) {
            if(i < n / 2) a[i] = 1;
            else a[i] = 2;
        }

        int idx = 0;
        int limit = 1e5-2;
        while(k > 0) {
            if(k >= limit) {
                a[idx] += limit;
                k -= limit;
                idx++;
            } else {
                a[idx] += k;
                break;
            }
        }

        printVector(a);
        
    }
    return 0;
}