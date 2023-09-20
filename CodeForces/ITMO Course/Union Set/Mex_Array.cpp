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
int findMEX(map<ll, ll>& mp) {
    int mex = 0;
    for(auto& e: mp) {
        if(e.first != mex) {
            e.second--;
            break;
        } else {
            mex++;
            e.second--;
        }
    }

    map<ll, ll> temp;
    for(auto& e: mp) {
        if(e.second != 0) {
            temp[e.first] = e.second;
        }
    }
    mp = temp;
    
    return mex;

}
int main() {
    // your code goes here
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout << fixed << setprecision(10);
    // // #ifndef ONLINE_JUDGE
    // // freopen("input.txt", "r", stdin);
    // // freopen("output.txt", "w", stdout);
    // // freopen("error.txt", "w", stderr);
    // // #endif
 
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> A(n);
        for (int i = 0; i < n; i++) cin >> A[i];
        map<ll, ll> mp;
        for(int i = 0; i < n; i++) {
            mp[A[i]]++;
        }
        vector<int> ans;
        while(mp.size() > 0) {
            int mex = findMEX(mp);
            ans.push_back(mex);
        }
        cout << ans.size() << endl;
        printVector(ans);
    }
    return 0;
}
