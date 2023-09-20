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
        int n;
        cin >> n;
        map<int, int> mp;
        int highest = 0;
        for(int i = 0; i < n; i++){
            int temp;
            cin >> temp;
            mp[temp]++;
        }


        int freq[500] = {0};
        int ans = 0;
        int t, freq;
        for(auto pp : mp){
            t = pp.first;
            freq = pp.second;
            
            
        }
    }
    return 0;
}