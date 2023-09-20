/* Problem 1: count of distinct pairs with given xor
int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    int cnt = 0;
    unordered_map<int, int> mp;
    for(int i = 0; i < n; i++) {
        if(mp.find(A[i]^B) != mp.end()) {
            cnt++;
        }
        mp[A[i]] = true;
    }
    return cnt;
}


problem 2: remove node which have exactly one child
/
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 /
TreeNode* Solution::solve(TreeNode* A) {
    if(A == NULL) return NULL;
    
    A->left = solve(A->left);
    A->right = solve(A->right);
    if(A->left == NULL && A->right != NULL) {
        return A->right;
    }
    if(A->left != NULL && A->right == NULL) {
        return A->left;
    }
    return A;
}



problem 3: merge all elements in 1, with minimum cost.
=> At any step, we can select only adjascent elements and replace those number with there sum, 
and cost of merging them will also be their sum.

int Solution::solve(vector<int> &A) {
    int n = A.size();
    int dp[n][n];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            dp[i][j] = 0;
        }
    }
    vector<int> preSum(n, 0);
    for(int i = 0; i < n; i++) {
        if(i == 0) preSum[i] =  A[i];
        else preSum[i] = A[i] + preSum[i-1];
    }
    for(int g = 0; g < n; g++) {
        for(int i = 0, j = g; j < n; j++, i++) {
            if(g == 0) {
                dp[i][j] = 0;
            } else if(g == 1) {
                dp[i][j] = A[i] + A[j];
            } else {
                int ans = INT_MAX;
                int leftAns, rightAns;
                int leftSum, rightSum;
                for(int k = i; k < j; k++) {
                    leftAns = dp[i][k];
                    rightAns = dp[k+1][j];
                    leftSum = preSum[k] - (i == 0 ? 0: preSum[i-1]);
                    rightSum = preSum[j] - preSum[k];
                    ans = min(ans, leftAns + rightAns + leftSum + rightSum);
                }
                dp[i][j] = ans;
            }
        }
    }
    return dp[0][n-1];
}



problem 4: count number of set bits in numbers from 1 to N. 
#define ll long long
int Solution::solve(int A) {
    
    ll ans = 0;
    while(A>0) {
        ll l2 = log2(A);
        ans += l2 * (pow(2, l2) / 2);
        A -= (pow(2, l2) - 1);
        ans += A;
        A--;
    }
    return ans% 1000000007;
}



*/