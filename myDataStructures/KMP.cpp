#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

// time: O(m) || space: O(m)
vector<int> build_pattern(string substr){
	int m = substr.length();
	vector<int> pattern(m, -1);

	int i = 1, j = 0;
	while(i < m){
		if(substr[j] == substr[i]){
			pattern[i] = j;
			j++;
			i++;
		} else if(j > 0){
			j = pattern[j-1] + 1;
		} else {
			i++;
		}
	}

	return pattern;
}

// time: O(n) || space: O(1)
bool does_match(string str, string substr, vector<int> pattern){
	int i = 0;
	int j = 0;
	int n = str.length(), m = substr.length();

	while(i + m - j <= n){
		if(str[i] == substr[j]){
			i++, j++;
		} else if(j > 0){
			j = pattern[j - 1] + 1;
		} else {
			i++;
		}
		if(j == m){
			return true;
		}
	}
	return false;
}

bool kmp_algo(string str, string substr){
	vector<int> pattern = build_pattern(substr);
	return does_match(str, substr, pattern);
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


	string str, substr;
	cin >> str >> substr;
	cout << kmp_algo(str, substr) << endl;
	return 0;
}  