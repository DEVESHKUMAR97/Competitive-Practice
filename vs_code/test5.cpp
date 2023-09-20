#include <iostream>
using namespace std;

int kmp(string para, string word) ;

int main() {
	// your code goes here
	string para = "aaabc";
	string word = "aabc";
	cout << kmp(para, word);
	return 0;
}


// O(n + m)

// kmp => lps(longest prefix which is proper suffix)

// abc => c, bc, abc  (proper suffix)

// abcab
// 00012

// ababcdabc

// abc

// abc#ababcdabc
// 0000121230123

// 0000000000000


// 0123456789
// aabc#aaabc
// 0100012234

// 0100012234


// i = 5, j = 10

// match = 4;

int kmp(string para, string word) {
    string str = word + "#" + para;
    
    int n = str.length();
    
    int a[n] = {0};
    
    int i = 0, j = 1;
    
    int match = 0;
    
    while(j < n) {
        
        if(str[i] == str[j]) {
            match++;
            a[j] = match;
            i++;
            j++;
        } else {
            if(i != 0) {
                i = a[j-1] - 1;
                match = a[a[j-1] - 1];
            }
            while(i != 0 && str[a[j-1]-1] != str[j]) {
                i = a[j-1] - 1;
                match = a[a[j-1] - 1];
            }
            if(i == 0) {
                a[j] = match;
                j++;
            }
        }
        
    }
    
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] == word.length()) {
            cnt++;
        }
    }
    
    return cnt;
}


















