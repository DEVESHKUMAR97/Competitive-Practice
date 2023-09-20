#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;
 
 
class box{
    public:
    ll x, y, z;
};

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
	    box I, F;
	    cin >> I.x >> I.y >> I.z;
	    cin >> F.x >> F.y >> F.z;
	    
	    queue <box> q;
	    q.push(I);
	    int ans = 0;
	    int nodes_left_in_layer = 1, nodes_in_next_layer = 0;
	    box nn; // for creating new node
	    ll k;
	    while(q.size() > 0){
	        box t = q.front();
	        q.pop();
	        
	        if(t.x == F.x && t.y == F.y && t.z == F.z){
	            cout << ans << endl;
	            break;
	        }
	        
	       // 3 addition at a time
	       if(F.x - t.x == F.y - t.y && F.y - t.y == F.z - t.z){
	           nn.x = F.x;
               nn.y = F.y;
               nn.z = F.z;
               q.push(nn);
               nodes_in_next_layer++;
	       }
	       
	       // 3 multiplication at a time
	       if(t.x != 0 && t.y != 0 && t.z != 0 && F.x % t.x == 0 && F.y % t.y == 0 && F.z % t.z == 0
            && F.x / t.x == F.y / t.y && F.y / t.y == F.z / t.z){
               nn.x = F.x;
               nn.y = F.y;
               nn.z = F.z;
               q.push(nn);
               nodes_in_next_layer++;
           }
           
            //   2 addition at a time
            if(F.x - t.x == F.y - t.y){
                nn.x = F.x;
                nn.y = F.y;
                nn.z = t.z;
                q.push(nn);
                nodes_in_next_layer++;
            }
            if(F.y - t.y == F.z - t.z){
                nn.x = t.x;
                nn.y = F.y;
                nn.z = F.z;
                q.push(nn);
                nodes_in_next_layer++;
            }
            if(F.z - t.z == F.x - t.x){
                nn.x = F.x;
                nn.y = t.y;
                nn.z = F.z;
                q.push(nn);
                nodes_in_next_layer++;
            }
            
            // 2 multiplication at a time
	       if(t.x != 0 && t.y != 0 && F.x % t.x == 0 && F.y % t.y == 0 && F.x / t.x == F.y / t.y){
               nn.x = F.x;
               nn.y = F.y;
               nn.z = t.z;
               q.push(nn);
               nodes_in_next_layer++;
           }
	       if(t.y != 0 && t.z != 0 && F.y % t.y == 0 && F.z % t.z == 0 &&  F.y / t.y == F.z / t.z){
               nn.x = t.x;
               nn.y = F.y;
               nn.z = F.z;
               q.push(nn);
               nodes_in_next_layer++;
           }
	       if(t.x != 0 && t.z != 0 && F.z % t.z == 0 && F.x % t.x == 0 && F.z / t.z == F.x / t.x){
               nn.x = F.x;
               nn.y = t.y;
               nn.z = F.z;
               q.push(nn);
               nodes_in_next_layer++;
           }
            
            // 1 addition at a time
               nn.x = F.x;
               nn.y = t.y;
               nn.z = t.z;
               q.push(nn);
               nodes_in_next_layer++;

               nn.x = F.x;
               nn.y = t.y + F.x - t.x;
               nn.z = t.z;
               q.push(nn);
               nodes_in_next_layer++;

               nn.x = F.x;
               nn.y = t.y;
               nn.z = t.z + F.x - t.x;
               q.push(nn);
               nodes_in_next_layer++;

               nn.x = F.x;
               nn.y = t.y + F.x - t.x;
               nn.z = t.z + F.x - t.x;
               q.push(nn);
               nodes_in_next_layer++;
               
               nn.x = t.x;
               nn.y = F.y;
               nn.z = t.z;
               q.push(nn);
               nodes_in_next_layer++;

               nn.x = t.x + F.y - t.y;
               nn.y = F.y;
               nn.z = t.z;
               q.push(nn);
               nodes_in_next_layer++;

               nn.x = t.x;
               nn.y = F.y;
               nn.z = t.z + F.y - t.y;
               q.push(nn);
               nodes_in_next_layer++;

               nn.x = t.x + F.y - t.y;
               nn.y = F.y;
               nn.z = t.z + F.y - t.y;
               q.push(nn);
               nodes_in_next_layer++;
               
               nn.x = t.x;
               nn.y = t.y;
               nn.z = F.z;
               q.push(nn);
               nodes_in_next_layer++;

               nn.x = t.x + F.z - t.z;
               nn.y = t.y;
               nn.z = F.z;
               q.push(nn);
               nodes_in_next_layer++;

               nn.x = t.x;
               nn.y = t.y + F.z - t.z;
               nn.z = F.z;
               q.push(nn);
               nodes_in_next_layer++;

               nn.x = t.x + F.z - t.z;
               nn.y = t.y+ F.z - t.z;
               nn.z = F.z;
               q.push(nn);
               nodes_in_next_layer++;
            
               // multiplication 1 at a time
               if(t.x != 0){
               	   k = F.x / t.x;
		           nn.x = t.x * k;
		           nn.y = t.y * k;
		           nn.z = t.z;
		           q.push(nn);
		           nodes_in_next_layer++;

		           nn.x = t.x * k;
		           nn.y = t.y;
		           nn.z = t.z * k;
		           q.push(nn);
		           nodes_in_next_layer++;

		           nn.x = t.x * k;
		           nn.y = t.y * k;
		           nn.z = t.z * k;
		           q.push(nn);
		           nodes_in_next_layer++;
		       }

		       if(t.y != 0){
               	   k = F.y / t.y;
		           nn.x = t.x * k;
		           nn.y = t.y * k;
		           nn.z = t.z;
		           q.push(nn);
		           nodes_in_next_layer++;

		           nn.x = t.x;
		           nn.y = t.y * k;
		           nn.z = t.z * k;
		           q.push(nn);
		           nodes_in_next_layer++;

		           nn.x = t.x * k;
		           nn.y = t.y * k;
		           nn.z = t.z * k;
		           q.push(nn);
		           nodes_in_next_layer++;
		       }

				if(t.z != 0){
               	   k = F.z / t.z;
		           nn.x = t.x;
		           nn.y = t.y * k;
		           nn.z = t.z * k;
		           q.push(nn);
		           nodes_in_next_layer++;

		           nn.x = t.x * k;
		           nn.y = t.y;
		           nn.z = t.z * k;
		           q.push(nn);
		           nodes_in_next_layer++;

		           nn.x = t.x * k;
		           nn.y = t.y * k;
		           nn.z = t.z * k;
		           q.push(nn);
		           nodes_in_next_layer++;
		       }



            nodes_left_in_layer--;
            if(nodes_left_in_layer == 0){
                nodes_left_in_layer = nodes_in_next_layer;
                nodes_in_next_layer = 0;
                ans++;
            }
            
	    }
	    

	}
	return 0;
}  