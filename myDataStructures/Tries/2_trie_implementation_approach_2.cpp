#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define casenum cout << "Case " << ++tt << ": "
#define endl '\n'
using namespace std;



/**
 * Approach 2: using child unordered_map
 * use `terminated` count to insert duplicate strings
*/

class Trie {
public:
	int terminated;
	unordered_map<char, Trie*> children;
	Trie(){
		terminated = 0;
	}
};

Trie* root = NULL;


// O(n); n = length of string to be inserted
void insert(string word){
	Trie *curr = root;
	for(auto ch : word){
		if(!curr->children.count(ch)){
			curr->children[ch] = new Trie();
		}
		curr = curr->children[ch];
	}
	curr->terminated++;
}

// O(n); n = length of string to be searched
int count_freq(string word){
	Trie *curr = root;
	for(auto ch : word){
		if(!curr->children.count(ch)){
			return 0;
		}
		curr = curr->children[ch];
	}
	return curr->terminated;
}

// O(n); n = length of string to be deleted
bool delete_string(string word){
	Trie *curr = root;
	for(auto ch : word){
		if(!curr->children.count(ch)){
			return false;
		}
		curr = curr->children[ch];
	}
	if(curr->terminated == 0){
		return false;
	} else {
		curr->terminated--;
		return true;
	}
}

// O(n); n = length of string
bool update(string oldWord, string newWord){
	if(delete_string(oldWord)){
		insert(newWord);
		return true;
	}
	return false;
}

/** Returns true  if there is any word in the trie that starts with the given prefix. */
bool startsWith(string prefix) {
    Trie *curr = root;
	for(auto ch : prefix){
		if(!curr->children.count(ch)){
			return false;
		}
		curr = curr->children[ch];
	}
	return true;
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
			cout << "string " << s << " frequency: " << count_freq(s);
		} else if(type == 3){
			string s;
			cin >> s;
			if(delete_string(s)){
				cout << "string deleted!!!";
			} else {
				cout << "string doesn't exist!!!";
			}
		} else if(type == 4){
			string s1, s2;
			cin >> s1 >> s2;
			if(update(s1, s2)){
				cout << "update successful!!!";
			} else {
				cout << "not updated!!!";
			}
		} else {
            string s;
			cin >> s;
            if(startsWith(s)) {
                cout << "string " << s << " prefix is present.";
            } else {
                cout << "string " << s << " prefix is not present.";
            }
			
        }
		cout << endl;
	}
    return 0;
}
