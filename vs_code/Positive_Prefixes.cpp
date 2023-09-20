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
        int a[n];
        for(int i = 0; i < n; i++) {
            a[i] = -(i+1);
        }
        int index = 0;
        while(k > 0 && index < n) {
            a[index] *= -1;
            index += 2;
            k--;
        }
        if(n & 1) index = n - 2;
        else index = n - 1;
        while(k > 0 && index >= 0) {
            a[index] *= -1;
            index -= 2;
            k--;
        }
        for(int i = 0; i < n; i++) {
            cout << a[i] << " ";
        } 
        cout << endl;
    }
    return 0;
}