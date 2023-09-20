#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define casenum cout << "Case " << ++tt << ": "
#define endl '\n'
using namespace std;

ll getSum(ll n){
    ll sum = 0;
    for(int i = 1; i * i <= n; i++){
        if(n % i == 0){
            sum += i;
            if(i * i != n){
                sum += (n / i);
            }
        }
    }
    return sum;
}


ll getAns(vector<int> arr){
    ll p = 1;
    for(auto val: arr){
        p *= val;
    }


    ll ans = 0;
    for(ll i = 1; i * i <= p; i++){
        if(p % i == 0){
            ans += getSum(i);
            if(i * i != p){
                ans += getSum(p / i);
            }
        }
    }
    return ans;
}

int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif
    cout<<fixed<<setprecision(10);
    
    // ll n;
    // cin >> n; 
    // vector<int> arr(n);
    // for(int i = 0; i < n; i++){
    //     cin >> arr[i];
    // }
    // cout << getAns(arr) << endl;

    unordered_map< pair<int, int>, ll> mp;
    mp[{1, 2}] = 2;
    mp[{1, 3}] = 4;
    for(auto pp: mp){
        cout << "{" << pp.first.first << ", " << pp.first.second << "} => " << pp.second << endl;
    }

    return 0;
}  

// Problem link : https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=3077
