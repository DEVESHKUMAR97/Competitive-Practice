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
        int n;
        cin >> n;
        // n = t;
        int a, b;
        if(n & 1) {
            a = n / 2;
            b = a + 1;
            int temp = a;
            int cnt = 0;
            while(temp % 10 == 9) {
                cnt++;
                temp /= 10;
            }
            int ext = 9 * cnt;
            int nums4 = ext / 8;
            if(a % 10 == 9) {
                // do something
                a -= 4;
                b += 4;
            }
        } else {
            a = n / 2;
            b = a;
            if(a % 10 == 0 || a % 10 == 9) {
                a -= 5;
                b += 5;
            } else {
                a -= 1;
                b += 1;
            }
        }
        cout << a << " " << b << endl;
    }
    return 0;
}