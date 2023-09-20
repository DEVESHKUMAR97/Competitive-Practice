#include<bits/stdc++.h>
using namespace std;
string solution(string s) {
    
    int n = s.length();
    vector<vector<bool> > dp(n, vector<bool>(n, false));
    int j;
    for(int length = 1; length <= n; length++) {
        for(int i = 0; i < n - (length - 1); i++) {
            j = i + length - 1;
            if(i == j) {
                dp[i][j] = true;
            } else if(i + 1 == j) {
                dp[i][j] = (s[i] == s[j]);
            } else {
                dp[i][j] = ((s[i] == s[j]) && dp[i+1][j-1]);
            }
        }
    }
    
    int startIndex = -1;
    int endIndex;
    int prefixPalLength;
    while(startIndex < n-1) {
        for(int j = n - 1; j > startIndex; j--) {
            if(dp[startIndex+1][j] == true) {
                endIndex = j;
                break;
            }
        }
        prefixPalLength = endIndex - startIndex;
        if(prefixPalLength == 1) {
            break;
        }
        startIndex = endIndex;
        if(startIndex == n - 1) break;
    }
    
    if(startIndex == n - 1) return "";
    
    return s.substr(startIndex + 1, n - startIndex);
    

}
