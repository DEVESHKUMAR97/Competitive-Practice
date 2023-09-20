#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define casenum cout << "Case " << ++tt << ": "
#define endl '\n'
using namespace std;

class Maker{
public:
    string name;
    int low, high;
};

int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif
    cout<<fixed<<setprecision(10);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        Maker makers[n];

        for(int i = 0; i < n; i++) {
            cin >> makers[i].name >> makers[i].low >> makers[i].high;
        }

        int q;
        cin >> q;
        while(q--) {
            int price;
            cin >> price;
            int count = 0;
            int index = -1;
            for(int i = 0; i < n; i++) {
                if(makers[i].low <= price && price <= makers[i].high) {
                    count++;
                    index = i;
                }
                if(count >= 2) break;
            }
            if(count == 1) {
                cout << makers[index].name << endl;
            } else {
                cout << "UNDETERMINED" << endl;
            }
        }

        if(t != 0) cout << endl;
    }

    return 0;
}  

// Problem link : https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=3678
