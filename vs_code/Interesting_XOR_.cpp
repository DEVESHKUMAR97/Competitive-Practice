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
        int c;
        cin >> c;
        int len = log2(c);
        int a = (1 << len) - 1;
        int b = a ^ c;
        cout << a * b << endl;

    }
    return 0;
}