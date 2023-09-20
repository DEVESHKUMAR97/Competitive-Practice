#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define casenum cout << "Case " << ++tt << ": "
#define endl '\n'
using namespace std;


vector<int> adj[300005];
vector<int> rev_adj[300005];
bool visited[300005];
stack<int> st;
int n;
int counting;

void fill_order(int u){
    visited[u] = true;

    for(int v : adj[u]){
        if(visited[v] == 0){
            fill_order(v);
        }
    }
    st.push(u);
}

void make_transpose(){
    for(int i = 0; i < n; i++){
        for(int v : adj[i]){
            rev_adj[v].push_back(i);
        }
    }
}

void dfs_visit(int u){
    visited[u] = 1;
    counting++;
    for(int v : rev_adj[u]){
        if(visited[v] == 0){
            dfs_visit(v);
        }
    }
}

void print(){
    for(int i = 0; i < n; i++){
        cout << i << " => ";
        for(int v : adj[i]){
            cout << v << " ";
        }
        cout << endl;
    }

    cout << "now rev :\n";
    for(int i = 0; i < n; i++){
        cout << i << " => ";
        for(int v : rev_adj[i]){
            cout << v << " ";
        }
        cout << endl;
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
        cin >> n;
        char ch;
        int u, v;
        st = stack<int>();
        for(int i = 0; i < n; i++){
            adj[i].clear();
            rev_adj[i].clear();
            visited[i] = 0;
        }
        for(int i = 0; i < n; i++){
            cin >> ch;
            u = i;
            v = (i+1) % n;
            if(ch == '-'){
                adj[u].push_back(v);
                adj[v].push_back(u);
            } else if(ch == '>'){
                adj[u].push_back(v);
            } else {
                adj[v].push_back(u);
            }
        }


        for(int i = 0; i < n; i++){
            if(visited[i] == 0){
                fill_order(i);
            }
        }

        make_transpose();

        // print();
        for(int i = 0; i < n; i++){
            visited[i] = 0;
        }
        int ans = 0;
        while(st.size() > 0){
            v = st.top();
            st.pop();
            if(visited[v] == 0){
                counting = 0;
                dfs_visit(v);
                if(counting == 1){
                    ans++;
                }
            }
        }
        cout << n - ans << endl;


    }
    return 0;
}