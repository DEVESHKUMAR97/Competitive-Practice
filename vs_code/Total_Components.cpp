#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define casenum cout << "Case " << ++tt << ": "
#define endl '\n'
using namespace std;


int MAXX = 1e5+2;
bool isPrime[(int)1e7+2];
int ans[(int)1e7+2];
bool drop[(int)1e7+2] = {0};

void generatePrimes() {
    
    for(int i = 2; i <= MAXX; i++) {
        drop[i] = false;
        isPrime[i] = true;
    }
    
    isPrime[0] = isPrime[1] = false;
    
    for(int i = 2; i * i <= MAXX; i++) {
        if(isPrime[i] == true) {
            for(int j = i * i; j <= MAXX; j += i) {
                isPrime[j] = false;
            }
        }
    }

    ans[2] = 1;
    for(int i = 3; i <= MAXX; i++) {
        if(isPrime[i]) {
            ans[i] = ans[i-1] + 1;
            drop[2*i] = true;
        } else {
            if(drop[i] == true) {
                ans[i] = ans[i-1] - 1;
            } else {
                ans[i] = ans[i-1];
            }
        }
    }
}
 
int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(10);

    generatePrimes();
 
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << ans[n] << endl;
    }
    return 0;
}