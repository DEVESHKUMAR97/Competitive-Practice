#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define casenum cout << "Case " << ++tt << ": "
#define endl '\n'
using namespace std;

vector<int> adj[100001];
int vis[100001], in[100001], low[100001];
vector< pair<int, int> > edges;
int timer = 0;

bool dfs(int node, int par) {
    timer++;
    vis[node] = 1;
    in[node] = low[node] = timer;

    for(int child : adj[node]) {
        if(child == par) continue;

        if(vis[child] == 1) {
            // node -> child is a back edge
            low[node] = min(low[node], in[child]);

            if(in[node] > in[child]) {
                // first time encountered this back - edge
                edges.push_back({node, child});
            }
        } else {
            // node -> child is forward edge
            if(dfs(child, node) ==  false) return false;

            // check if bridge
            if(low[child] > in[node]) {
                return false;
            }

            low[node] = min(low[node], low[child]);
            edges.push_back({node, child});

        }
    }
    return true;
}
 
int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(10);
 
    int n, m;
    cin >> n >> m;
    int u, v;
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if(dfs(1, -1)) {
        for(int i = 0; i < edges.size(); i++) {
            cout << edges[i].first << " " << edges[i].second << endl;
        }
    } else {
        cout << 0 << endl;
    }
    

    return 0;
}