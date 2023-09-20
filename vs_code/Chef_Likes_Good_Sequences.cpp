#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define casenum cout << "Case " << ++tt << ": "
#define endl '\n'
using namespace std;

int solve(int *a, int n){
    int temp = 1;
    for(int i = 2; i <= n; i++){
        if(a[i] != a[i-1]){
            temp++;
        }
    }
    return temp;
}
 
int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(10);
 
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        int a[n+1];
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        int ans = solve(a, n);
        int x, y;
        while(q--){
            cin >> x >> y;
            if(n == 1) { cout << 1 << endl; continue;}
            if(a[x] == y){
                cout << ans << endl;
            } else {
                if(x == 1){
                    if(a[1] == a[2]){
                        ans++;
                    } else if(a[2] == y){
                        ans--;
                    }
                } else if(x == n){
                    if(a[n] == a[n-1]){
                        ans++;
                    } else if(a[n-1] == y){
                        ans--;
                    }
                } else {
                    if(a[x-1] == a[x] && a[x] == a[x+1]){
                        ans += 2;
                    } else if(a[x-1] == a[x]){
                        if(a[x+1] != y){
                            ans++;
                        }
                    } else if(a[x+1] == a[x]){
                        if(a[x-1] != y){
                            ans++;
                        }
                    } else if(a[x-1] == y && y == a[x+1]){
                        ans -= 2;
                    } else if(a[x-1] == y){
                        ans--;
                    } else if(a[x+1] == y){
                        ans--;
                    }
                }
                cout << ans << endl;
            }
            a[x] = y;
        }
    }
    return 0;
}