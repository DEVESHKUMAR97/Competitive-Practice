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

const int bitMax = 32;

bool isValid(int i, int j, vector<vector<int>>& bitFreq, int k) {
    int num = 0;
    if(i != 0) {
        for(int bit = 0; bit < bitMax; bit++) {
            if(bitFreq[j][bit] - bitFreq[i-1][bit] == j - i + 1) {
                num |= (1 << bit);
            }
        }
    } else {
        for(int bit = 0; bit < bitMax; bit++) {
            if(bitFreq[j][bit] == j + 1) {
                num |= (1 << bit);
            }
        }
    }
    return num >= k;
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
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        vector<vector<int>> bitFreq(n, vector<int> (32, 0));
        for(int i = 0; i < n; i++) {
            if(i == 0) {
                for(int j = 0; j < bitMax; j++) {
                    bitFreq[i][j] = ((a[i] & (1 << j)) > 0);
                }
            } else {
                for(int j = 0; j < bitMax; j++) {
                    bitFreq[i][j] = bitFreq[i-1][j] + ((a[i] & (1 << j)) > 0);
                }
            }
        }

        int q;
        cin >> q;
        while(q--) {
            int l, k;
            cin >> l >> k;
            l--;
            int low = l, high = n - 1;
            int mid;
            int ans = -1;
            while(low <= high) {
                mid = low + (high - low) / 2;
                if(isValid(l, mid, bitFreq, k)) {
                    ans = mid + 1;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }

            cout << ans << " ";
        }
        cout << endl;
        
    }
    return 0;
}