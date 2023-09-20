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
        int n, m;
        cin >> n >> m;
        string G[n];
        char ans[n][m];
        for(int i = 0; i < n; i++) {
                cin >> G[i];
        }

        int flag = 1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                char ch = ((i+j) % 2 == 0 ? 'R' : 'W'); 
                if(G[i][j] == '.' || G[i][j] == ch) {
                    ans[i][j] = ch;
                } else {
                    flag = 0;
                    break;
                }
            }
        }


        if(flag == 0) {
            flag = 1;
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    char ch = ((i+j) % 2 == 0 ? 'W' : 'R'); 
                    if(G[i][j] == '.' || G[i][j] == ch) {
                        ans[i][j] = ch;
                    } else {
                        flag = 0;
                        break;
                    }
                }
            }
        }

        if(flag == 1) {
            cout << "YES" << endl;
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    cout << ans[i][j];
                }
                cout << endl;
            }
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}