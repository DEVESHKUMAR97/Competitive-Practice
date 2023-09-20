#define maxx 100003
#define ll long long
ll dist[maxx];
int ans[maxx];
vector<pair<int, int> > adj[maxx];

struct Box {
    int par;
    int curr;
    int wt;
};

struct MyComp {
    bool operator() (Box a, Box b) {
        return a.wt < b.wt;
    }
};

int Solution::solve(const int A, const vector<vector<int> > &B, const int C, const int D) {
    for(int i = 1; i <= A; i++) {
        dist[i] = 1e18;
        adj[i].clear();
        ans[i] = 1e9+1;
    }
    for(int i = 0; i < B.size(); i++) {
        adj[B[i][0]].push_back({B[i][1], B[i][2]});
        adj[B[i][1]].push_back({B[i][0], B[i][2]});
    }
    
    dist[C] = 0;
    
    priority_queue<Box, vector< Box >, MyComp> minHeap;
    Box temp;
    temp.par = -1;
    temp.curr = C;
    temp.wt = 0;
    minHeap.push(temp);
    
    while(minHeap.size() > 0) {
        temp = minHeap.top();
        minHeap.pop();
        
        for(int i = 0; i < adj[temp.curr].size(); i++) {
            if(dist[adj[temp.curr][i].first] > dist[temp.curr] + adj[temp.curr][i].second) {
                dist[adj[temp.curr][i].first] = dist[temp.curr] + adj[temp.curr][i].second;
                ans[adj[temp.curr][i].first] = min(ans[temp.curr], adj[temp.curr][i].second);
                Box b;
                b.par = temp.curr;
                b.curr = adj[temp.curr][i].first;
                b.wt = adj[temp.curr][i].second;
                minHeap.push(b);
            } else if(dist[adj[temp.curr][i].first] == dist[temp.curr] + adj[temp.curr][i].second) {
                ans[adj[temp.curr][i].first] = min(ans[adj[temp.curr][i].first], min(ans[temp.curr], adj[temp.curr][i].second));
            }
        }
    }
    
    
    return ans[D];
    
    
}
