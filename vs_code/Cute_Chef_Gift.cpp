#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define casenum cout << "Case " << ++tt << ": "
#define endl '\n'
using namespace std;

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
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
         int a[n];
         for(int i = 0; i < n; i++){
             cin >> a[i];
         }
         int index = 0;
         for(int i = 1; i < n; i++){
             if(gcd(a[0], a[i]) != 1){
                 index = i;
             }
         }
         cout << index + 1 << endl;
    }
    return 0;
}