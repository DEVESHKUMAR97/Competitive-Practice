// Q1. Implement pow(x, n), which calculates x raised to the power n (i.e. xn).

// Eg: 

// Input: x = 2.00000, n = 10
// Output: 1024.00000

// Constraints: 
// -100.0 < x < 100.0
// -2^31 <= n <= 2^31-1
// -10^4 <= x^n <= 10^4


// 2 ^ (2.3)
// 2 ^ (2 + .3)
// 2 ^ 2

// pow(), n = 1234567.89, x = 1.2
// x^(a+b) = x^a * x^b

// x ^ n == 

// n = I + F



#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long int 
using namespace std;

// returns x ^ n ( n > 0)
// time : O(log(n)) / space : O(1)
ll power(ll x, ll n){
    
    ll result = 1;
    
    while(n > 0){
        if(n & 1){
            result = result * x;
        }
        x = x * x;
        n = n >> 1; 
    }
    return result;
}

int main() {
    ll x, n;
    cin >> x >> n;
    
    double ans = 1.0;
    if(n >= 0) ans = power(x, n);
    else ans = ans / power(x, -n);
    cout << ans << endl;
    
}




// x^n == (x*x) ^ (n / 2)

//brute force soln
// x = 99
// n = 30000

// 2 ^ -3
// 1/ (2 ^ 3)





// 127.0.0.1 www.facebook.com