#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;
 

ll maxsize = 1e9 + 1;
ll freq[maxsize];
map < ll , vector < pair <ll , ll > > > mp;
map < ll , vector < pair <ll , ll > > > :: itreator itr;


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
		mp.clear();
	    int n;
	    cin >> n;
	    ll l, r, vel;
	    for(int i = 0; i < n; i++){
	    	cin >> l >> r >> vel;
	    	mp[vel].push_back({l, r});
	    }
	    int flag = 0;

	    for(itr = mp.begin(); itr != mp.end(); itr++){
	    	sort((itr -> second).begin(), (itr->second).end());
	    	for(int i = 0; (itr->second).size() - 2; i++){
	    		if((itr->second)[i].second >= (itr->second)[i+1].first 
	    			&& (itr->second)[i].second >= (itr->second)[i+1].first ){
	    			flag = 1;
	    		break;
	    		}
	    	}
	    }
	    if(flag == 1){
	    	cout << "YES\n";
	    } else {
	    	cout << "NO\n";
	    }

	    
	}
	return 0;
}  