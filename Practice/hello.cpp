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
  	
  	int c;
  	cin >> c;
  	while(c--){
  		int n, t, m;
  		cin >> n >> t >> m;
  		queue<int> left_bank, right_bank;
  		for(int i = 0; i < m; i++){
  			int arrival;
  			string side;
  			cin >> arrival >> side;
  			if(side == "left"){
  				left_bank.push(arrival);
  			} else {
  				right_bank.push(arrival);
  			}
  		}

  		vector<int> ans(m);
  		int time = 0;
  		queue<int> ferry;
  		bool on_left = true;
  		while(left_bank.size() == 0 && right_bank.size() == 0){
  			if(on_left == true){
  				
  			}
  		}
  	}

    return 0;
}  

// Problem link : https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=3077
