#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define casenum cout << "Case " << ++tt << ": "
#define endl '\n'
using namespace std;

const ll mm = (1ll << 32);
const int N = 3e5 + 2;
vector<int> adj[N];
bitset<N> visited;
vector<int> parent(N);

vector<ll> weight(N);
// vector<ll> self_product(N);
map< pair<int, int> , ll> mp;

void dfs(int u, ll prod){
    visited[u] = 1;
    ll temp_prod = (weight[u] * weight[u]) % mm;
    prod = (prod + temp_prod) % mm;
    mp[{u, u}] = prod;

    for(int v: adj[u]){
        if(visited[v] == 0){
            parent[v] = u;
            dfs(v, prod);
        }
    }

}

ll find_prod(int u, int v){
    if(u == v){
        return mp[{u, u}];
    }
    if(mp.find({u, v}) != mp.end()){
        return mp[{u, v}];
    }

    ll parent_prod = find_prod(parent[u], parent[v]);
    ll temp_prod = (weight[u] * weight[v]) % mm;

    return mp[{u, v}] = ((parent_prod + temp_prod) % mm);
}


int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(10);
 
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> weight[i];

    int u, v;
    for(int i = 1; i < n; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    parent[1] = -1;
    dfs(1, 0);


    ll ans;
    while(q--){
        cin >> u >> v;
        ans = find_prod(u, v);
        cout << ans << endl;
    }

    return 0;
}