#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define casenum cout << "Case " << ++tt << ": "
#define endl '\n'
using namespace std;

vector<int> fac;
int dp[32][32];

// return a vector of grps size represents required distribution of fac starting from index 
vector<int> solve(int index, int grps) {
    if(fac.size() - index == grps) {
        vector<int> ans;
        for(int i = index; i < fac.size(); i++){
            ans.push_back(fac[i]);
        }
        return ans;
    }
    if(grps == 1) {
        vector<int> ans(1);
        ans[0] = 1;
        for(int i = index; i < fac.size(); i++){
            ans[0] *= fac[i];
        }
        return ans;
    }

    vector<int> option1 = solve(index + 1, grps - 1);
    option1.push_back(fac[index]);
    int sum1 = 0;
    for(int val: option1) {
        sum1 += val;
    }

    vector<int> option2 = solve(index + 1, grps);
    int sum2 = 0;
    for(int val: option2) {
        sum2 += val;
    }
    int temp, min_sum2 = 100000000;
    int min_index = -1;
    for(int i = 0; i < option2.size(); i++){
        temp = sum2 - option2[i];
        temp += (option2[i] * fac[index]);
        if(min_sum2 > temp) {
            min_sum2 = temp;
            min_index = i;
        }
    }
    option2[min_index] *= fac[index];

    if(min_sum2 < sum1) {
        return option2;
    } else {
        return option1;
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
        int k, x;
        cin >> k >> x;

        fac.clear();

        int prev = -1;

        for(int i = 2; i * i <= x; i++){
            while(x % i == 0){
                if(i != prev){
                    fac.push_back(i);
                    prev = i;
                } else {
                    fac[fac.size() - 1] *= i;
                }
                x /= i;
            }
        }
        if(x > 1) fac.push_back(x);
        // for(int val: fac) cout << val << " ";
        // cout << endl;

        if(k >= fac.size()){
            int sum = 0;
            for(auto val: fac){
                sum += val;
            }
            cout << (sum + (k - fac.size())) << endl;
        } else {
            // for(int i = 0; i < 32; i++){
            //     for(int j = 0; j < 32; j++){
            //         dp[i][j] = -1;
            //     }
            // }
            vector<int> final_ans = solve(0, k);
            int sum = 0;
            for(int val: final_ans){
                sum += val;
            }
            cout << sum << endl;
        }
        
        // for(int i = sqrt(x); i >= 1; i--){
        //     if(x % i == 0 && __gcd(i, x / i) == 1){
        //         cout << (i + (x / i) + (k - 2)) << endl;
        //         break;
        //     }
        // }
    }
    return 0;
}