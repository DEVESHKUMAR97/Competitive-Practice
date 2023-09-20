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
        string a, b;
        cin >> a >> b;
        int fa[26] = {0};
        int fb[26] = {0};
        for(char ch: a) {
            fa[ch-'a']++;
        }
        for(char ch: b) {
            fb[ch-'a']++;
        }

        bool flag = true;
        for(int i = 0; i < 26; i++) {
            int temp = min(fa[i], fb[i]);
            fa[i] -= temp;
            fb[i] -= temp;
        }
        bool isAZero = true, isBZero = true;
        for(int i = 0; i < 26; i++) {
            if(fa[i] > 0) isAZero = false;
            if(fb[i] > 0) isBZero = false;
        }
        if(isAZero && isBZero) {
            cout << "YES\n";
        } else if(!isAZero && !isBZero) {
            cout << "NO\n";
        } else if(!isAZero) {
            int odds = 0;
            for(int i = 0; i < 26; i++) {
                if(fa[i] % 2 != 0) {
                    odds++;
                }
            }
            if(odds > 1) {
                cout << "NO\n";
            } else {
                cout << "YES\n";
            }
        } else {
            int odds = 0;
            for(int i = 0; i < 26; i++) {
                if(fb[i] % 2 != 0) {
                    odds++;
                }
            }
            if(odds > 1) {
                cout << "NO\n";
            } else {
                cout << "YES\n";
            }
        }
    }
    return 0;
}































