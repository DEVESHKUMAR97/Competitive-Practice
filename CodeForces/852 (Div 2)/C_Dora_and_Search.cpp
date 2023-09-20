#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define casenum cout << "Case " << ++tt << ": "
#define endl '\n'
using namespace std;
 
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
        vector<int> p(n);
        for(int i = 0; i < n; i++) cin >> p[i];

        deque<int> windowMin, windowMax;
        for(int i = 0; i < n; i++) {
            if(i == 0) {
                windowMax.pu
            }
        }





        // vector<int> preMin(n), sufMin(n), preMax(n), sufMax(n);
        // for(int i = 0; i < n; i++) {
        //     if(i == 0) {
        //         preMin[i] = p[i];
        //         preMax[i] = p[i];
        //     } else {
        //         preMin[i] = min(p[i], preMin[i-1]);
        //         preMax[i] = max(p[i], preMax[i-1]);
        //     }
        // }
        // for(int i = n-1; i >= 0; i--) {
        //     if(i == n - 1) {
        //         sufMin[i] = p[i];
        //         sufMax[i] = p[i];
        //     } else {
        //         sufMin[i] = min(p[i], sufMin[i+1]);
        //         sufMax[i] = max(p[i], sufMax[i+1]);
        //     }
        // }

        // int i = 0, j = n - 1;
        // bool flag = false;
        // while(i < j) {
        //     if(preMin[j] ==  p[j] || preMax[j] == p[j]) {
        //         j--;
        //     } else if (sufMin[i] == p[i] || sufMax[i] == p[i]) {
        //         i++;
        //     } else {
        //         cout << i + 1 << " " << j + 1 << endl;
        //         flag = true;
        //         break;
        //     }
        // }
        // if(flag == false) {
        //     cout << -1 << endl;
        // }
    }
    return 0;
}