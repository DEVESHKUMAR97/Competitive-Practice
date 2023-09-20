#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define casenum cout << "Case " << ++tt << ": "
#define endl '\n'
using namespace std;

void printVector(vector<int>& a) {
    for(int i = 0; i < a.size(); i++) {
        cout << a[i] << ", ";
    }
    cout << endl;
}

// vector<int> parent;
// vector<int> height;
int parent[100005];
int height[100005];

int find(int u) {
    if(parent[u] < 0) return u;
    return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if(u != v) {
        if(height[u] >= height[v]) {
            parent[u] += parent[v];
            parent[v] = u;
            if(height[u] == height[v]) {
                height[u]++;
            }
        } else if(height[v] > height[u]) {
            parent[v] += parent[u];
            parent[u] = v;
        }
    }
}


int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(10);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // freopen("error.txt", "w", stderr);
    // #endif
 
    int n, m;
    cin >> n >> m;
    // parent = vector<int>(n, -1);
    // height = vector<int>(n, 1);
    memset(parent, -1, sizeof(parent));
    memset(height, 1, sizeof(height));
    while(m--) {
        string type;
        int u, v;
        cin >> type >> u >> v;
        if(type == "union") {
            merge(u, v);
        } else {
            cout << (find(u) == find(v) ? "YES" : "NO") << endl;
        }
    }

    return 0;
}
