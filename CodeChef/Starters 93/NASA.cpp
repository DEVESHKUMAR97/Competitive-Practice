
#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define casenum cout << "Case " << ++tt << ": "
#define endl '\n'
using namespace std;

int reverse(int a) {
    int aRev = 0;
    while(a > 0) {
        aRev = aRev * 10 + (a%10);
        a /= 10;
    }
    return aRev;
}

bool isPal(int a) {
    int aRev = reverse(a);

    return aRev == a;
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

    int maxN = 35536;
    vector<int> pals;
    for(int i = 0; i <= maxN; i++) {
        if(isPal(i)) {
            pals.push_back(i);
        }
    }
    cout << pals.size() << endl;
 
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<ll> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        unordered_map<ll, ll> mp;
        ll ans = 0;
        int target;
        for(int i = 0; i < n; i++) {
            mp[a[i]]++;
            for(int j = 0; j < pals.size(); j++) {
                target = pals[j] ^ a[i];
                ans += (mp[target]);
            }
        }
        cout << ans << endl;

    }
    return 0;
}
