#include <bits/stdc++.h>
using namespace std;

// int solve(vector<int>& A, int target) {
    
//     int low, high, mid;
//     int n = A.size();

//     low = 0;
//     high = n - 1;

//     while(low <= high) {
//         mid = low + (high - low) / 2;

//         if(A[mid] == target) return mid;
//         if(A[low] <= A[mid]) {
//             // check in left side
//             if(A[low] <= target && target <= A[mid]) {
//                 high = mid - 1;
//             } else {
//                 low = mid + 1;
//             }
//         } else {
//             // check in right side
//             if(A[mid] <= target && target <= A[high]) {
//                 low = mid + 1;
//             } else {
//                 high = mid - 1;
//             }
//         }
//     }
//     return -1;
// }

class Node {
    public:
    int val;
    Node* left;
    Node* right;
    Node(int val) {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

void solve2(Node* root, map<int,int>& mp, int index) {
    if(root == NULL) {
        return;
    }

    queue<pair<Node*, int> > qu;

    qu.push({root, index});

    while(qu.size() > 0) {
        pair<Node*, int> temp = qu.front();
        qu.pop();

        mp[temp.second] = temp.first -> val;

        if(temp.first ->left != NULL) {
            qu.push({temp.first -> left, temp.second - 1});
        }
        if(temp.first ->right != NULL) {
            qu.push({temp.first -> right, temp.second + 1});
        }
    }
}


int main() {
    // int n;
    // cin >> n;
    // vector<int> arr(n);

    // for(int i = 0; i < n; i++) {
    //     cin >> arr[i];
    // }
    // int target;
    // cin >> target;
    // cout << solve(arr, target);

    Node* root ;
    
    root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> right = new Node(4);
    root -> right -> right = new Node(5);
    root -> left -> right -> right = new Node(6);




    map<int, int> mp;
    vector<int> ans;

    solve2(root, mp, 0);

    for(auto pp: mp) {
        ans.push_back(pp.second);
    }
    
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ", ";
    }
    cout << endl;
    return 0;
}

