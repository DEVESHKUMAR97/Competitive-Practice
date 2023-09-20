
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
        int n;
        cin >> n;
        vector<int> a(n+1);
        unordered_map<int, int> mp;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            mp[a[i]] =  i;
        }

        int ans = 0;
        for(int i = 1; i <= n; i++) {
            if(a[i] == 1) continue;
            if(mp[a[i] - 1] > i) {
                ans++;
            }
        }
        cout << ans << endl;
        
    }
    return 0;
}
