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
        string s;
        cin >> s;
        int n = s.length();
        int freq[n][27];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < 27; j++) {
                freq[i][j] = 0;
            }
        }
        int index;
        for(int i = 0; i < n; i++) {
            if(s[i] == '?') {
                index = s[i] - '?' + 26;
            } else {
                index = s[i] - 'a';
            }
            for(int j = 0; j < 27; j++) {
                if(j == index) {
                    if(i == 0) {
                        freq[i][j] = 1;
                    } else {
                        freq[i][j] = freq[i-1][j] + 1;
                    }
                } else {
                    if(i != 0) {
                        freq[i][j] = freq[i-1][j];
                    }
                }
            }
        }
        
    }
    return 0;
}