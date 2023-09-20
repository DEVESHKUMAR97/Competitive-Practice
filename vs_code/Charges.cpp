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
        string s;
        cin >> s;
        char prev = s[0];
        int dist = 0;
        for(int i = 1; i < s.length(); i++) {
            if(s[i] != prev) {
                dist += 1;
            } else {
                dist += 2;
            }
            prev = s[i];
        }

        int q[k];
        for(int i = 0; i < k; i++) {
            cin >> q[i];
            q[i]--;
        }

        for(int i = 0; i < k; i++) {
            if(s[q[i]] == '1') {
                s[q[i]] = '0';
            } else {
                s[q[i]] = '1';
            }

            if(q[i] > 0) {
                if(s[q[i] - 1] == s[q[i]])
                    dist++;
                else dist--;
            }

            
            if(q[i] < n - 1) {
                if(s[q[i] + 1] == s[q[i]])
                    dist++;
                else dist--;
            }
            cout << dist << endl;
        }



    }
    return 0;
}