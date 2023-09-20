
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
        vector<int> a(n);
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++) cin >> a[i], mp[a[i]]++;

        int ans = 1;
        for(auto e: mp) if(e.second > (n + 1) / 2) {ans = -1; break;}
        if(ans == -1) {
            cout << -1 << endl;
            continue;
        }

        sort(a.begin(), a.end());

        if(n % 2 == 0) {
            for(int i = 0; i < n / 2; i++) {
                cout << a[i] << " " << a[i+n/2] << " ";
            }
            cout << endl;
        } else {
            for(int i = 0; i < (n + 1) / 2; i++) {
                cout << a[i] << " ";
                if(i + (n+1) / 2 < n) {
                    cout << a[i + (n+1)/2] << " ";
                }
            }
            cout << endl;
        }

        
    }
    return 0;
}
