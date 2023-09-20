#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define casenum cout << "Case " << ++tt << ": "
#define endl '\n'
using namespace std;

int maxN = 100001;
vector<int> adj[100001];
int vis[100001];
int size[100001];

int dfs(int u) {
    vis[u] = 1;

    int sz = 0;
    for(int v : adj[u]) {
        if(vis[v] == 0) {
            sz += dfs(v);
        }
    }
    return size[u] = sz + 1;
}
 
int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(10);
 
    int t;
    cin >> t;
    while(t--){
        for(int i = 0; i < maxN; i++) {
            adj[i].clear();
            vis[i] = 0;
        }

        int n;
        cin >> n;
        int u, v;
        for(int i = 0; i < n - 1; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(1);

        for(int i = 1; i <= n; i++) {
            cout << size[i] << " ";
        }
        cout << endl;
    }
    return 0;
}