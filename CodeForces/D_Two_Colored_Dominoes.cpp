
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
        int n, m;
        cin >> n >> m;
        vector<string> mat;
        for(int i = 0; i < n; i++) cin >> mat[i];
        vector<int> row(n, 0);
        vector<int> col(m, 0);

        for(int i =0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] != '.') {
                    row[i]++;
                    col[j]++;
                }
            }
        }

        bool minusOne = false;
        for(int i = 0; i < n; i++) {
            if(row[i] & 1) {
                minusOne = true;
                break;
            }
        }
        for(int i = 0; i < m; i++) {
            if(col[i] & 1) {
                minusOne = true;
                break;
            }
        }

        if(minusOne) {
            cout << -1 << endl;
            continue;
        }

        
    }
    return 0;
}
