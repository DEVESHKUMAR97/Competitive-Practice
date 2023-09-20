#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    vector <Node *> children;
};

Node* make_new_node(int data){
    Node* n = new Node();
    n -> data = data;
    return n;
}

Node* construct_tree(int arr[], int n){
    stack <Node * > st;
    Node *root = NULL;
    
    for(int i = 0; i < n; i++){
        if(arr[i] == -1){
            st.pop();
        } else {
            if(st.size() == 0){
                root = make_new_node(arr[i]);
                st.push(root);
            } else {
                Node *n = make_new_node(arr[i]);
                (st.top() -> children).push_back(n);
                st.push(n);
            }
        }
    }
    return root;
}

void display(Node* root){
    cout << root -> data << " ==> ";
    vector <Node*> children = root -> children;
    for(int i = 0; i < children.size(); i++){
        cout << children[i] -> data << ", ";
    }
    cout << "." << endl;
    
    for(int i = 0; i < children.size(); i++){
        display(children[i]);
    }
}

int size(Node* root){
    if(root == NULL) return 0;
    int ans = 1;
    vector <Node*> children = root -> children;
    for(int i = 0; i < children.size(); i++){
        ans += size(children[i]);
    }
    return ans;
}

int main(){
    // int arr[] = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};
    // int n = sizeof(arr)/ sizeof(int);
    int n;
    cin >> n;
    
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    Node* root = construct_tree(arr, n);
    // display(root);
    cout << size(root) << endl;
    
    return 0;
}