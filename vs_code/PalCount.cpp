#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define casenum cout << "Case " << ++tt << ": "
#define endl '\n'
using namespace std;


string s;
int n, k;

ll countPal(int index, bool makeSmall) {

    if(index >= (n+1) / 2) {
        return makeSmall == false;
    }


    ll ans;
    char minChar;
    if(makeSmall) {
        minChar = min(s[index], s[n - 1 - index]);
        if(s[index] != s[n - 1 - index] && s[index] > s[n - 1 - index]) {
            ans = (minChar - 'a' + 1) * countPal(index + 1, !makeSmall);
        } else if(s[index] != s[n - 1 - index] && s[index] < s[n - 1 - index]) {
            ans = (minChar - 'a' + 1) * countPal(index + 1, !makeSmall);
        } else {
            if(minChar > 'a') {
                ans = (minChar - 'a') * countPal(index + 1, !makeSmall) + countPal(index + 1, makeSmall);
            } else {
                ans = countPal(index + 1, makeSmall);
            }
        }
    } else {
        ans = k * countPal(index + 1, makeSmall);
    }

    return ans;
}


int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(10);
 
    int t;
    cin >> t;
    int tt = 0;
    while(t--){
        
        cin >> n >> k;

        cin >> s;

        casenum;
        cout << countPal(0, true) << endl;

        

        
    }
    return 0;
}