
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
        string s;
        cin >> s;
        int firstOneIdx = -1;
        for(int i = 0; i + 2 < n; i++) {
            if(s[i] == '1') {
                firstOneIdx = i;
                break;
            }
        }
        if(firstOneIdx == -1) {
            cout << s << endl;
            continue;
        }

        bool isFound = false;
        for(int i = n - 3; i >= firstOneIdx; i--) {
            s[i+1] = '0';
            s[i+2] = '0';
        }
        cout << s << endl;
    }
    return 0;
}
