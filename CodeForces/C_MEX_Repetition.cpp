
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
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        k %= (n+1);

        vector<int> temp = a;
        int mex = 0;
        for(int i = 0; i < n; i++) {
            if(temp[i] != mex) {
                break;
            }
            mex++;
        }

        // cerr << mex << endl;

        int idxToModify = n - k;
        a[idxToModify] = mex;
        // printVector(a);

        // right shift k times
        for(int i = 0; i < idxToModify; i++) {
            temp[(i + k) % n] = a[i];
        }
        int len = k - 1;
        for(int i = idxToModify + 1; i < n; i++) {
            temp[(i+len) % n] = a[i];
        }

        temp[k-1] = mex;
        for(int i = 0; i < n; i++) cout << temp[i] << " ";
        cout << endl;
        
    }
    return 0;
}

// 293	adityajangir71  	18	0:39:01	 0:06:56	 0:11:09	 0:20:19	 0:39:01