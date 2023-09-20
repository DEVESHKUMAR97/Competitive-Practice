
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
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        vector<pair<int, int>> vec;
        vec.push_back({0, 0});
        for(int i = 1; i <= n; i++) {
            vec.push_back({a[i], i});
        }

        sort(vec.begin(), vec.end());

        vector<int> b(n+1);
        int k = n;
        for(int i = 1; i <= n; i++) {
            b[vec[i].second] = k;
            k--;
        }

        for(int i = 1; i <= n; i++) cout << b[i] << " ";
        cout << endl;
        
    }
    return 0;
}
