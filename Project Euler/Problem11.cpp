#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;
 
int arr[20][20];
int solve(){

	int ans = -1;
	int prod;
	for(int i = 0; i < 20; i++){
		for(int j = 0; j < 20; j++){

			// down
			if(i + 3 < 20){
				prod = 1;
				for(int k = 0; k < 4; k++){
					prod *= arr[i+k][j];
				}
				ans = max(ans, prod);
			}

			// up
			if(i - 3 >= 0){
				prod = 1;
				for(int k = 0; k < 4; k++){
					prod *= arr[i-k][j];
				}
				ans = max(ans, prod);
			}

			// left
			if(j - 3 >= 0){
				prod = 1;
				for(int k = 0; k < 4; k++){
					prod *= arr[i][j-k];
				}
				ans = max(ans, prod);
			}

			// right
			if(j + 3 < 20){
				prod = 1;
				for(int k = 0; k < 4; k++){
					prod *= arr[i][j+k];
				}
				ans = max(ans, prod);
			}

			// 45deg
			if(i - 3 >= 0 && j + 3 < 20){
				prod = 1;
				for(int k = 0; k < 4; k++){
					prod *= arr[i-k][j+k];
				}
				ans = max(ans, prod);
			}

			// 135deg
			if(i - 3 >= 0 && j - 3 >= 0){
				prod = 1;
				for(int k = 0; k < 4; k++){
					prod *= arr[i-k][j-k];
				}
				ans = max(ans, prod);
			}


			// 225deg
			if(j - 3 >= 0 && i + 3 < 20){
				prod = 1;
				for(int k = 0; k < 4; k++){
					prod *= arr[i+k][j-k];
				}
				ans = max(ans, prod);
			}


			// -45deg
			if(i + 3 < 20 && j + 3 < 20){
				prod = 1;
				for(int k = 0; k < 4; k++){
					prod *= arr[i+k][j+k];
				}
				ans = max(ans, prod);
			}

		}
	}
	return ans;
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

	
	for(int i = 0; i < 20; i++){
		for(int j = 0; j < 20; j++){
			cin >> arr[i][j];
		}
	}

	cout << solve() << endl;
	return 0;
}  