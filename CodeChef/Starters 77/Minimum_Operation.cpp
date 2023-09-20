#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define casenum cout << "Case " << ++tt << ": "
#define endl '\n'
using namespace std;

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}

const int maxN = 1e6+2;
vector<int> primes;
vector<bool> isPrime(maxN, true);

void generatePrimes() {
    isPrime[0] = isPrime[1] = false;

    for(int i = 2; i * i <= maxN; i++) {
        if(isPrime[i]) {
            for(int j = i * i; j <= maxN; j += i) {
                isPrime[j] = false;
            }
        }
    }    
    for(int i = 0; i <= maxN; i++) {
        if(isPrime[i]) {
            primes.push_back(i);
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
    while(t--) {
       int n, m;
       cin >> n >> m;
       vector<int> a(n);
       set<int> s;
       for(int i = 0; i < n ;i++)
        {
            cin >> a[i];
            s.insert(a[i]);

        }
        if(s.size() == 1) {
            cout << 0 << endl;
            continue;
        }
        int flag = 0;
        for(int i = primes.size()-1; i >= 0; i--) {
            if(primes[i] <= m && s.find(primes[i]) == s.end()) {
                cout << 1 << endl;
                cout << primes[i] << endl;
                flag = 1;
                break;
            }
        }
        if(flag == 1) continue;


        cout << 2 << endl;
        cout << 2 << " " << 3 << endl;
    }

    
    return 0;
}
