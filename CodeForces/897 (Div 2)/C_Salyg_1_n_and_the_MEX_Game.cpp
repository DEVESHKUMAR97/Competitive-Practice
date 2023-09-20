
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

int findMex(vector<int>& a) {
    for(int i = 0; i < a.size(); i++) {
        if(a[i] != i) {
            return i;
        }
    }
    return a.size() + 1;
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
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());

        int mex = findMex(a);
        cout << mex << endl;
        // fflush(stdout);
        cout.flush();

        int y;
        cin >> y;
        while(y != -1 && y != -2) {
            cout << y << endl;
            cout.flush();
            cin >> y;
            // if(y != -1 || t > 0) {
            //     cout << endl;
            // }
            // cout.flush();
            // fflush(stdout);
        }
        // fflush(stdout);
        // cout.flush();
        if(y == -2) return 0;
        
    }
    return 0;
}
