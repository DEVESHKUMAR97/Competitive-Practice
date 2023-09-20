
#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define casenum cout << "Case " << ++tt << ": "
#define endl '\n'
using namespace std;

template <typename T>
void printVector(vector<T>& a) {
    for(int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

template <typename T>
void printMap(map<T, T>& mp) {
    for(auto& e: mp) {
        cout << e.first << " => " << e.second << endl;
    }
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
        string s;
        cin >> s;
        string ans(n + 1, '0');

        int diffPairs = 0;
        for(int i = 0; i < n / 2; i++) {
            if(s[i] != s[n - 1 - i]) {
                diffPairs++;
            }
        }
        int samePairs = n / 2 - diffPairs;


        if(n % 2 == 0) {
            for(int i = 0; i <= n; i++) {
                if(i >= diffPairs) {
                    if(i == diffPairs) {
                        ans[i] = '1';
                    } else if((i - diffPairs) % 2 == 0 && samePairs > 0) {
                        ans[i] = '1';
                        samePairs--;
                    }
                }
            }
        } else {
            for(int i = 0; i <= n; i++) {
                if(i >= diffPairs) {
                    if(i == diffPairs) {
                        ans[i] = '1';
                    } else if((i - diffPairs) % 2 == 0 && samePairs > 0) {
                        ans[i] = '1';
                        samePairs--;
                    } else if((i-diffPairs) % 2 == 1 && samePairs >= 0) {
                        ans[i] = '1';
                        if(samePairs == 0) samePairs--;
                    }
                }
            }
        }

        cout << ans << endl;

        
    }
    return 0;
}
