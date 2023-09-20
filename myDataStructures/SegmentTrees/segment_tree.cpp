
#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define casenum cout << "Case " << ++tt << ": "
#define endl '\n'
using namespace std;


// using DFS, build the min sub segment tree rooted at nodeIndex and contains the answer of subarray[arrStartIndex:arrEndIndex]
// time: O(2*n-1)
void buildMinTree(vector<int>& tree, int nodeIndex, vector<int>&arr, int arrStartIndex, int arrEndIndex) {

    if(arrStartIndex > arrEndIndex) return; // not possible

    // leaf node
    if(arrStartIndex == arrEndIndex) {
        tree[nodeIndex] = arr[arrStartIndex];
        return;
    }


    int mid = arrStartIndex + (arrEndIndex - arrStartIndex) / 2;
    
    // build left sub tree
    buildMinTree(tree, nodeIndex*2 + 1, arr, arrStartIndex, mid);

    // build right sub tree
    buildMinTree(tree, nodeIndex*2 + 2, arr, mid + 1, arrEndIndex);

    // tree will always be a complete binary tree, that means each node have either 0 or 2 children
    tree[nodeIndex] = min(tree[nodeIndex*2+1], tree[nodeIndex*2+2]); // min of left and right subtree
}
 
/**
 * returns the minimum element of arr[queryStart:queryEnd], from tree rooted at nodeIndex.
 * time: O(log(n)) == O(hight of tree)
 * 
 * Case 1: Complete OverLap => when query range completly overlap node range => ans = tree[index]
 *              qs======================qe      |   qs===============qe
 *                   ns=============ne          |   ns===============ne
 * Case 2: Partial OverLap => when query range partially overlap node range 
 *          => then call both left and right subtree with same query range
 *              qs==================qe          |        qs===============qe
 *                   ns==================ne     |   ns===============ne
 * Case 1: No OverLap => when query range not overlapping with node range => return invalid ans(like infinite)
 *              qs=========qe                   |                   qs========qe
 *                              ns=======ne     | ns=======ne
 * 
 * */ 
int minRangeQuery(vector<int>& tree, int nodeIndex, int nodeStartIndex, int nodeEndIndex, int queryStart, int queryEnd) {
    // Case 3: no overlapping
    if(queryEnd < nodeStartIndex || nodeEndIndex < queryStart) {
        return INT_MAX;
    }

    // Case 1: complete overlapping
    if(queryStart <= nodeStartIndex && nodeEndIndex <= queryEnd) {
        return tree[nodeIndex];
    }


    // Case 2: Partial overlapping
    int mid = nodeStartIndex + (nodeEndIndex - nodeStartIndex) / 2;
    int leftMin = minRangeQuery(tree, 2*nodeIndex + 1, nodeStartIndex, mid, queryStart, queryEnd);
    int rightMin = minRangeQuery(tree, 2*nodeIndex + 2, mid + 1, nodeEndIndex, queryStart, queryEnd);
    return min(leftMin, rightMin);

}

/**
 * time: O(log(n)) == O(hight of tree)
 * */ 
void updateNode(vector<int>&tree, int nodeIndex, int nodeStartIndex, int nodeEndIndex, int queryIndex, int queryValue) {
    // Case 3: no overlapping
    if(queryIndex < nodeStartIndex || nodeEndIndex < queryIndex) {
        return;
    }

    // Case 1: complete overlapping
    if(nodeStartIndex == nodeEndIndex) {
        tree[nodeIndex] = queryValue;
        return;
    }


    // Case 2: Partial overlapping
    int mid = nodeStartIndex + (nodeEndIndex - nodeStartIndex) / 2;
    updateNode(tree, 2*nodeIndex + 1, nodeStartIndex, mid, queryIndex, queryValue);
    updateNode(tree, 2*nodeIndex + 2, mid + 1, nodeEndIndex, queryIndex, queryValue);
    tree[nodeIndex] = min(tree[nodeIndex*2+1], tree[nodeIndex*2+2]);
}

/**
 * time: O(log(n)) == O(hight of tree)
 * */ 
void updateRange(vector<int>&tree, int nodeIndex, int nodeStartIndex, int nodeEndIndex, 
        int queryStart, int queryEnd, int queryValue) {
    // Case 3: no overlapping
    if(queryEnd < nodeStartIndex || nodeEndIndex < queryStart) {
        return;
    }

    // Case 1: complete overlapping
    if(nodeStartIndex == nodeEndIndex) {
        tree[nodeIndex] += queryValue;
        return;
    }


    // Case 2: Partial overlapping
    int mid = nodeStartIndex + (nodeEndIndex - nodeStartIndex) / 2;
    updateRange(tree, 2*nodeIndex + 1, nodeStartIndex, mid, queryStart, queryEnd, queryValue);
    updateRange(tree, 2*nodeIndex + 2, mid + 1, nodeEndIndex, queryStart, queryEnd, queryValue);
    tree[nodeIndex] = min(tree[nodeIndex*2+1], tree[nodeIndex*2+2]);
}
int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(10);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif
 
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> tree(4*n+2);

    //build the tree
    buildMinTree(tree, 1, arr, 0, n - 1);


    return 0;
}
