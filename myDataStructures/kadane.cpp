#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define casenum cout << "Case " << ++tt << ": "
#define endl '\n'
using namespace std;

int DAC_max_sum_subarray(int arr[], int low, int high){
	if(high < low) return 0;
    if(high == low ) return arr[high];
	int mid = low + (high - low) / 2;
	int option1 = DAC_max_sum_subarray(arr, low, mid);
	int option2 = DAC_max_sum_subarray(arr, mid + 1, high);

	int left_sum = 0, left_sum_max = 0;
	for(int i = mid; i >= low; i--){
		left_sum += arr[i];
		if(left_sum > left_sum_max){
			left_sum_max = left_sum;
		}
	}
	int right_sum = 0, right_sum_max = 0, option3;
	for(int i = mid + 1; i <= high; i++){
		right_sum += arr[i];
		if(right_sum > right_sum_max){
			right_sum_max = right_sum;
		}
	}
    option3 = left_sum_max + right_sum_max;
	return max(option3, max(option2, option1));
}

int kadane_max_sum_subarray(int arr[], int n){
	int sum = 0, max_sum = 0;
	for(int i = 0; i < n; i++){
		sum += arr[i];
		if(sum > max_sum){
			max_sum = sum;
		}
		if(sum < 0){
			sum = 0;
		}
	}
	return max_sum;
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
    cout<<fixed<<setprecision(10);

    int t;
    cin >> t;
    while(t--){
    	int n;
    	cin >> n;
    	int arr[n];
    	for(int i = 0; i < n; i++){
    		cin >> arr[i];
    	}
    	cout << DAC_max_sum_subarray(arr, 0, n - 1) << endl;
    	cout << kadane_max_sum_subarray(arr, n) << endl;
    }

    return 0;
}  

// Problem link : https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=166


// 3
// 16
// 3 5 -9 1 3 -2 3 4 7 2 -9 6 3 1 -5 4
// 3
// 3 -2 7
// 5
// 1 2 0 9 5