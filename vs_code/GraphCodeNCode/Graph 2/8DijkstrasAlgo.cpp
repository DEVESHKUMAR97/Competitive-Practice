#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define casenum cout << "Case " << ++tt << ": "
#define endl '\n'
using namespace std;

typedef pair<int, int> pp;
vector< pp > adj[100001];
int dist[100001];

int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(10);
 
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) dist[i] = INT_MAX;

    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    priority_queue<pp, vector<pp>, greater<pp> > pq;
    dist[1] = 0;
    pq.push({0, 1});

    while(pq.size() > 0) {
        pp p = pq.top();
        pq.pop();   
        int curr = p.second;
        int curr_d = p.first;


        for(pp edge : adj[curr]) {
            if(curr_d + edge.second < dist[edge.first]) {
                dist[edge.first] = curr_d + edge.second;
                pq.push({dist[edge.first], edge.first});
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;


    return 0;
}