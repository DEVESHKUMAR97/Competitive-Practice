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
 
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int a[n];
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int temp;
        vector<int> arr;
        for(int i = 0; i < n/2; i++) {
            temp = abs(a[i] - a[n-i-1]);
            if(temp != 0) arr.push_back(temp);
        }
        bool ans = true;
        if(k == n) {
            if(arr.size() == 0) ans = true;
            else ans = false;
        } else {
            if(k & 1) ans = true;
            else if(n % 2 == 1) ans = true;
            else {
                // map<int, int> mp;
                int cnt = 0;
                for(int item: arr) {
                    // mp[item]++;
                    if(item % 2 != 0) cnt++;
                }
                // for(auto pp: mp) {
                //     if(pp.second % k != 0) {
                //         ans = false;
                //         break;
                //     }
                // }
                ans = (cnt % 2 == 0);
            }
        }

        cout << (ans ? "YES" : "NO") << endl;


    }
    return 0;
}
