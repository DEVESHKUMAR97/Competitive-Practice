#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;
 
class Trie
{
public:
	int terminated;
	unordered_map<char, Trie*> children;
	Trie(){
		terminated = 0;
	}
};

Trie *root;
void insert(string s){
	Trie *curr = root;
	for(auto ch : s){
		if(!curr->children.count(ch)){
			curr->children[ch] = new Trie();
		}
		curr = curr->children[ch];
	}
	curr->terminated++;
}

int count_freq(string s){
	Trie *curr = root;
	for(auto ch : s){
		if(!curr->children.count(ch)){
			return 0;
		}
		curr = curr->children[ch];
	}
	return curr->terminated;
}

bool delete_string(string s){
	Trie *curr = root;
	for(auto ch : s){
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
	for(int i = 0; i < n; i++){
		string s;
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
		} else {
			string s1, s2;
			cin >> s1 >> s2;
			if(update(s1, s2)){
				cout << "update successful!!!";
			} else {
				cout << "not updated!!!";
			}
		}
		cout << endl;
	}

	
	return 0;
}  

/*
1 -> -2 -> 4 -> -6 -> -10

pos = 1-> 4 
neg = -2 -> -6 -> -10

-10 -> -6 -> -2 -> 1 -> 4






// /***
// *
// *   Hi Devesh
// *   Welcome!!!
// *
// /
// // 2nd round


1. Find the next largest number lexicographically (dictionary order) of a given number
eg - 1253686
ans: 1253866
+++

321 => 123


23542 => 24235


1342

4321 =>
bool isDecreasing(string s) {
    int n = s.length();
    
    for(int i = 1; i < n; i++) {
        if(s[i] > s[i-1]) return false; 
    }
    return true;
}

void reverseExhausted(string &s, int index, int n) {
    int sz = n - index - 1; // 2
    sz /= 2;
    index++;
    int i = 0;
    while(sz--) {
        char temp = s[index + i];
        s[temp + i] = s[n - 1 - i];
        s[n - 1 - i] = s[temp + i];
        i++;
    }
}

string nextPermutation(string str) {
    string s = str;
    if(isDecreasing(s)) {
        reverse(s.begin(), s.end());
        return s;
    }
    
    int index;
    for(int i = n - 2; i >= 0; i--) {
        if(s[i] < s[i+1]) {
            index = i;
            break;
        }
    }
    
    
    for(int i = n - 1; i >= 0; i--) {
        if(s[i] > s[index]) {
            char temp = s[i];
            s[i] = s[index];
            s[index] = temp;
            break;
        }
    }
    
    reverseExhausted(s, index, n);
    return s;
}


1342;

57182

4431






1. Given an array consiting of N integers representing the number of coins in each pile, 
and an integer H, the task is to find the minimum number of coins that must be collected from a 
single pile per hour such that all the piles are emptied in not greater than H hours.

eg. arr[] = {3, 6, 7, 11}, H = 800000
ans: 4

low = 12, high = 11, mid = 10

bool isValid(vector<int> &a, int H, int n, int ans) {
    
    
    int reqHours = 0;
    
    for(int i = 0; i < n; i++) {
        reqHours += ceil((1.0 * a[i]) / ans);
    }
    
    return reqHours <= H;
}

MAX
time : O(log(MAX) * n)
space : O(1)
int solve(vector<int> a, int H) {
    
    if(a.size() == 0 || H == 0 || a.size() > H) {
        return -1;
    }
    
    int n = a.size();
    
    int mx = INT_MIN;
    
    
    for(int i = 0; i < n; i++) {
        mx = max(mx, a[i]);
    }


    2 3 3 4 5
    
    int high = mx, low = 1, mid, ans = -1;
    
    
    
    while(low <= high) {
        mid = low + (high - low) / 2;
        
        if(isValid(a, H, n, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    
    return ans;
    
}



==========================
3rd Round
Hello 

class Test {
    
    private int r1, r2;
    private bool lockR1;
    private bool lockR2;
    ExecuterService threads = new ThreadPool(2);
    
    private void fun2() {
        if(lockR1 == false) {
            r2 = 10;
            lockR2 = true;
        }
    }
    
    private void fun() {
        if(lockR1 == false) {
            r1 = 3;
            lockR1 = true;
        }
    }
    public static void main(String [] args) {
        lockR1 = false;
        lockR2 = false;
        threads.submit(() -> {
           fun(); 
           lockR1 = false;
        });
        
        threads.submit(() -> {
            if()
            fun();
            
        });
    }
}

/* Print the outline nodes of a given tree

         1
      /     \
     2       3
    /  \     / \
   4    5   6    7
    \    / .      \   
     9 10          12
    / \
   8   11

Outline nodes of the above tree are 1 2  4 8 9 10 12 7 3 
      1
     /  \ 
         3
      
      
      
-3 -2 -1 0 1 2

db1, db2, task3 
distribution 1-.6, 2-.3, 3-.1
          
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
*/











