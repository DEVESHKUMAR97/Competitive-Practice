#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define casenum cout << "Case " << ++tt << ": "
#define endl '\n'
using namespace std;

int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif
    cout<<fixed<<setprecision(10);
  
    int n, m;
    while(cin >> n >> m, n != 0 || m != 0){
    	bitset<1000002> visited;
    	bool ans = true;
    	for(int i = 0; i < n; i++){
    		int start, end;
    		cin >> start >> end;
    		if(ans == true){
	    		end--;
	    		for(int j = start; j <= end; j++){
	    			if(visited[j] == 0){
	    				visited[j] = 1;
	    			} else {
	    				ans = false;
	    				break;
	    			}
	    		}
	    	}
    	}
    	for(int i = 0; i < m; i++){
    		int start, end, interval;
    		cin >> start >> end >> interval;
    		if(ans == true){
    			end--;
    			for(int k = 0; start + k * interval <= 1000000; k++){
    				if(ans == true){
	    				for(int j = start + k * interval; j <= end + k * interval && j <= 1000000; j++){
	    					if(visited[j] == 0){
			    				visited[j] = 1;
			    			} else {
			    				ans = false;
			    				break;
			    			}
	    				}
    				}
    			}
    		}
    	}
    	cout << (ans ? "NO CONFLICT\n" : "CONFLICT\n");
    }

    return 0;
}  

// Problem link : https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=3139
 