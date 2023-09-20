#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;
 

class Trie {
public:
	int terminated = 0;
	unordered_map<char, Trie*> children;
};

Trie *root;

void insert(string s) {
	Trie *curr = root;
	for(char ch: s) {
		if(curr -> children.count(ch) == 1) {
			// present
			curr = curr->children[ch];
		} else {
			// not present
			curr->children[ch] = new Trie();
			curr = curr->children[ch];
		}
	}
	curr->terminated++;
}

int count_freq(string s) {
	Trie *curr = root;
	for(char ch: s) {
		if(curr -> children.count(ch) == 1) {
			// present
			curr = curr->children[ch];
		} else {
			// not present
			return 0;
		}
	}
	return curr->terminated;
}

bool delete_string(string s) {

	Trie *curr = root;
	for(char ch: s) {
		if(curr -> children.count(ch) == 1) {
			// present
			curr = curr->children[ch];
		} else {
			// not present
			return false;
		}
	}
	if(curr -> terminated == 0) {
		return false;
	} else {
		curr->terminated--;
		return true;
	}
}


bool update(string oldS, string newS){
	if(delete_string(oldS)){
		insert(newS);
		return true;
	}
	return false;
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

	root = new Trie();

	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		string s;
		cin >> s;
		insert(s);
	}
	return 0;
}  