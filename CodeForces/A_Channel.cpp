
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
        int n, a, q;
        cin >> n >> a >> q;
        string s;
        cin >> s;
        int currOnline = a;
        int ans = 2; // maybe
        int plusCount = 0;
        for(int i = 0; i < s.length(); i++) {
            if(currOnline == n) {
                ans = 1; // yes
                break;
            }
            if(s[i] == '+') {
                plusCount++;
                currOnline++;
            } else {
                currOnline--;
            }
            if(currOnline == n) {
                ans = 1; // yes
                break;
            }
        }
        if(a + plusCount < n) {
            ans = 0; // no
        }

        if(ans == 0) {
            cout << "NO\n";
        } else if(ans == 1) {
            cout << "YES\n";
        } else {
            cout << "MAYBE\n";
        }
    }
    return 0;
}
