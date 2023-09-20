
#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define casenum cout << "Case " << ++tt << ": "
#define endl '\n'
using namespace std;


// Code refered from : https://www.geeksforgeeks.org/compute-ncrp-using-fermat-little-theorem/

// vector<unsigned long long> ppower;
unsigned long long fac[100002 + 1];

// unsigned long long ppower[100002] = {0};

/* Iterative Function to calculate (x^y)%p
in O(log y) */
unsigned long long power(unsigned long long x,
                                  int y, int p)
{
    // if(y < 100000 && ppower[y] != 0) return ppower[y];

    unsigned long long res = 1; // Initialize result
 
    x = x % p; // Update x if it is more than or
    // equal to p
 
    while (y > 0)
    {
     
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;
 
        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    // if(y < 100000) ppower[y] = res;
    return res;
}
 
// Returns n^(-1) mod p
unsigned long long modInverse(unsigned long long n, 
                                            int p)
{
    return power(n, p - 2, p);
}
 
// Returns nCr % p using Fermat's little
// theorem.
unsigned long long nCrModPFermat(unsigned long long n,
                                 int r, int p)
{
    // If n<r, then nCr should return 0
    if (n < r)
        return 0;
    // Base case
    if (r == 0)
        return 1;
 
    // Fill factorial array so that we
    // can find all factorial of r, n
    // and n-r

 
    return (fac[n] * modInverse(fac[r], p) % p
            * modInverse(fac[n - r], p) % p)
           % p;
}
 
int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(10);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // freopen("error.txt", "w", stderr);
    // #endif


    // ppower = vector<unsigned long long>(100002, 0)
    fac[0] = 1;
    for (int i = 1; i <= 100002; i++)
        fac[i] = (fac[i - 1] * i) % mod;
    int t;
    cin >> t;
    while(t--){
        int n; 
        cin >> n;
        vector<ll> A(n+1);
        for(int i = 0; i <= n; i++) {
            if(i == 0) A[i] = 0;
            else cin >> A[i];
        }
        sort(A.begin(), A.end());

        ll ans = 0;
        for(int i = 1; i <= n; i++) {
            if(i < A[i]) {
                continue;
            }

            if(i == A[i]) {
                ans = (ans + power(2, n - i, mod)) % mod;
            } else {
                ll tempAns = (nCrModPFermat(i-1, A[i] - 1, mod) * power(2, n - i, mod)) %mod;
                ans = (ans + tempAns) % mod;
            }

        }
        cout << ans << endl;


    }
    return 0;
}
