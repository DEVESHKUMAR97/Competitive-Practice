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
    while(t--) {
        int n; cin >> n;
        string s;
        cin >> s;

        int ones = 0;
        for(char ch: s) {
            if(ch == '1') {
                ones++;
            }
        }
        int zeros = n - ones;
        int pairs = min(zeros, ones);
        if(pairs % 2 == 1) {
            cout << "Zlatan" << endl;
        } else {
            cout << "Ramos" << endl;
        }
    }

    
    return 0;
}
