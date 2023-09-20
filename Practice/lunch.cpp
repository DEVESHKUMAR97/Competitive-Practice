#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

int graph[10000001][1000000+1];
int V = 1001;
int n, q;
int inf = 1e9 + 1;
 
void floydWarshall ()  
{  
    /* dist[][] will be the output matrix  
    that will finally have the shortest  
    distances between every pair of vertices */
    int  i, j, k;  
  
    /* Initialize the solution matrix same  
    as input graph matrix. Or we can say  
    the initial values of shortest distances 
    are based on shortest paths considering  
    no intermediate vertex. */
    // for (i = 1; i <= n; i++)  
    //     for (j = 1; j <= n; j++)  
    //         dist[i][j] = graph[i][j];  
  
    /* Add all vertices one by one to  
    the set of intermediate vertices.  
    ---> Before start of an iteration,  
    we have shortest distances between all  
    pairs of vertices such that the  
    shortest distances consider only the  
    vertices in set {0, 1, 2, .. k-1} as 
    intermediate vertices.  
    ----> After the end of an iteration,  
    vertex no. k is added to the set of  
    intermediate vertices and the set becomes {0, 1, 2, .. k} */
    for (k = 1; k <= n; k++)  
    {  
        // Pick all vertices as source one by one  
        for (i = 1; i <= n; i++)  
        {  
            // Pick all vertices as destination for the  
            // above picked source  
            for (j = 1; j <= n; j++)  
            {  
                // If vertex k is on the shortest path from  
                // i to j, then update the value of dist[i][j]  
                if (graph[i][k] + graph[k][j] < graph[i][j])  
                    graph[i][j] = graph[i][k] + graph[k][j];  
            }  
        }  
    }  
  
    // Print the shortest distance matrix  
    // printSolution(dist);  
}  
  
// // /* A utility function to print solution */
// void printSolution()  
// {  
//     cerr<<"The following matrix shows the shortest distances"
//             " between every pair of vertices \n";  
//     for (int i = 1; i <= n; i++)  
//     {  
//         for (int j = 1; j <= n; j++)  
//         {  
//             if (graph[i][j] == inf)  
//                 cerr<<"*"<<"     ";  
//             else
//                 cerr<<graph[i][j]<<"     ";  
//         }  
//         cerr<<endl;  
//     }  
// }  
int initialize_graph(){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			graph[i][j] = inf;
		}
	}
	for(int i = 1; i <= n; i++){
		graph[i][i] = 0;
	}
}


int main() {
	// your code goes here

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
	#endif

	int t;
	cin>>t;
	while(t--){
		
		cin >> n >> q;
		int u, v;

		initialize_graph();

		for(int i = 0; i < n - 1; i++){
			cin >> u >> v;
			graph[u][v] = 1;
			graph[v][u] = 1;
		}

		// printSolution();

	    floydWarshall();

	    // printSolution(); 
	    int a, da, b, db, flag, x; 
	    while(q--){
	    	cin >> a >> da >> b >> db;
	    	flag = 0;
	    	for(x = 1; x <= n; x++){
	    		if(graph[x][a] == da && graph[x][b] == db){
	    			flag = 1;
	    			break;
	    		}
	    	}
	    	if(flag == 1){
	    		cout << x << endl;
	    	} else {
	    		cout << -1 << endl;
	    	}
	    }
	}
	return 0;
}  