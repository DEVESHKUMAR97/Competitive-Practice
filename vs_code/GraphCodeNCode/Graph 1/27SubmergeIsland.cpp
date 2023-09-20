#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define casenum cout << "Case " << ++tt << ": "
#define endl '\n'
using namespace std;

vector<int> adj[100001];
int vis[100001], in[100001], low[100001];
set<int> aPoints;
int timer = 0;

void dfs(int node, int par) {
    timer++;
    vis[node] = 1;
    in[node] = low[node] = timer;

    int children = 0;
    for(int child : adj[node]) {
        if(child == par) continue;

        if(vis[child] == 1) {
            // node -> child is a back edge
            low[node] = min(low[node], in[child]);
        } else {
            // node -> child is forward edge
            dfs(child, node);

            // check if bridge
            if(low[child] >= in[node] && par != -1) {
                aPoints.insert(node);
            }

            low[node] = min(low[node], low[child]);
            children++;
        }
    }
    
    if(par == -1 && children > 1) {
        aPoints.insert(node);
    }
}
 
int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(10);
 
    int n, m;
    while(cin >> n >> m, n && m) {
        for(int i = 0; i <= n; i++) {
            adj[i].clear();
            vis[i] = 0;
            aPoints.clear();
        }
        int u, v;
        for(int i = 0; i < m; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(1, -1);
        cout << aPoints.size() << endl;
    }
    

    return 0;
}