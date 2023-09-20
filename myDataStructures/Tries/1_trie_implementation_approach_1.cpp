#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define casenum cout << "Case " << ++tt << ": "
#define endl '\n'
using namespace std;



/**
 * Approach 1: using child array
 * use `isEnd` only when all string are unique
*/

class Trie {
    public:
        Trie* child[26];
        bool isEnd;

        Trie() { // constructor
            memset(child, 0, sizeof(child));
            isEnd = false;
        }
};

Trie* root = NULL;


// O(n); n = length of string to be inserted
void insert(string &s) {
    Trie* curr = root;
    int idx;
    for(char ch: s) {
        idx = ch-'a';
        if(curr -> child[idx] == NULL) {
            curr -> child[idx] = new Trie();
        }
        curr = curr -> child[idx];
    }
    curr -> isEnd = true;
}

// O(n); n = length of string to be searched
bool search_string(string &s) {
    Trie* curr = root;
    int idx;
    for(char ch: s) {
        idx = ch - 'a';
        if(curr -> child[idx] == NULL) {
            return false;
        }
        curr = curr -> child[idx];
    }
    return curr -> isEnd;
}
 
int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(10);
    #ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
	#endif


    // creating the root 
    root = new Trie();
 
    int n;
    cin >> n;
    string s;
    for(int i = 0; i < n; i++) {
        cin >> s;
        insert(s);
    }
    int q;
	cin >> q;
	while(q--){
		int type;
		cin >> type;
		if(type == 1){
			string s;
			cin >> s;
			insert(s);
			cout << "successful insertion!!!";
		} else if(type == 2){
			string s;
			cin >> s;
            if(search_string(s)){
				cout << "string " << s << " is present!!!";
			} else {
				cout << "string " << s << " is not present!!!";
			}
		}
		cout << endl;
	}
    return 0;
}
