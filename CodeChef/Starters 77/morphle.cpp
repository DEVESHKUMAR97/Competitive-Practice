#include <iostream>
#include<bits/stdc++.h>
using namespace std;


void printStrings(vector<string> &strs, int n, int k, string outputTillNow, int index) {
    if(index == n) {
        cout << outputTillNow << endl;
        return;
    }
    
    string temp;
    for(int i = 0; i < k; i++) {
        temp = outputTillNow + strs[index][i];
        printStrings(strs, n, k, temp, index + 1);
    }
    
    
    // j : 0 -> K
    //     i : 0-> N
    //         st.push(strs[i][j])
            
    //     print(st)
    //     pop(st)
}



void printStrings2(vector<string> &strs, int n, int k) {
    stack<char> st;
    
    for(int j = 0; j < k; j++) {
        for(int i = 0; i < n; i++) {
            st.push(strs[i][j]);
        }
        
    }
    
}

// abc
// xyz

int main() {
	// your code goes here
	int n = 3, k = 3;
	vector<string> strs;
	string temp;
	for(int i = 0; i < n; i++) {
	    cin >> temp;
	    strs.push_back(temp);
	}
	printStrings(strs, n, k, "", 0);
// 	printStrings2(strs, n, k);
	return 0;
}
/*
Given N strings each length K
Ex. K=2, N=3
ab
xy
mn

axm
axn
aym
ayn

somya@morphle.in



rec()

Print all possible output strings of length n such that ith char of each output string is from ith input string
Ex.
axm
ayn
byn

...
..

/*
input strings
n = 3, k = 2

k ^ n




ab
xy
ab
*/







