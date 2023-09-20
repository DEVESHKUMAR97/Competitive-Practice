#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#define ll long long

using namespace std;
map<int, vector<int> > adj;
map<int, int> vis;

vector< vector<int> > ans;
void dfs(int u, int ct){
    vis[u] = 1;
    ans[ct].push_back(u);
    for(auto v: adj[u]){
        if(vis[v] == 0){
            dfs(v, ct);
        }
    }
}
int main() {
    
    adj.clear();
    vis.clear();
    ans.clear();
    int u, v;
    while(cin >> u >> v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int n = adj.size();
    
    for(auto itr = adj.begin(); itr != adj.end(); itr++){
        vis[itr->first] = 0;
    }
    int ct = 0;
    for(auto itr = adj.begin(); itr != adj.end(); itr++){
        if(vis[itr->first] == 0){
            ans.push_back(vector<int>());
            dfs(itr->first, ct);
            sort(ans[ct].begin(), ans[ct].end());
            ct++;
        }
    }
    sort(ans.begin(), ans.end());
    for(auto row: ans){
        for(auto val: row){
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}





























class Solution {
public:
    vector<string> ans;
    bool isPop(char a, char b) {
        if(a == '*') return true;
        return b != '*';
    }
    map<char, int> mp;
    mp['+'] = -1;
    mp['-'] = -2;
    mp['*'] = -3;
    vector<int> inToPost(string s) {
        vector<int> ans;
        stack<char> st;
        string temp;
        for(int i = 0; i < s.length(); i++) {
            if('0' <= s[i] && s[i] <= '9') {
                temp += s[i];
            } else {
                ans.push_back(stoi(temp));
                while(st.size() > 0 && isPop(st.top(), s[i])) {
                    ans.push_back(mp[st.top()]);
                    st.pop();
                }
                st.push(s[i]);
                temp = "";
            }
        }
        if(temp != "") ans.push(stoi(temp));
        while(st.size() > 0) {
            ans.push_back(mp[st.top()]);
            st.pop();
        }
        return ans;
    }
    
    int evaluate(string s) {
        vector<int> pf = inToPost(s);
        // cout << s << ": " << pf << endl; 
        stack<int> st;
        int temp;
        for(int i = 0; i < pf.size(); i++) {
            if('0' <= pf[i] && pf[i] <= '9') {
                temp += pf[i];
            } else {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                if(pf[i] == '+') {
                    st.push(b+a);
                } else if(pf[i] == '-') {
                    st.push(b-a);
                } else {
                    st.push(b*a);
                }
            }
        }
        return st.top();
    }
    void solve(string &num, int index, string output, int target) {
        if(index == num.length()) {
            int value = evaluate(output);
            if(value == target) ans.push_back(output);
            return;
        }
        
        solve(num, index + 1, output + "+" + num[index], target);
        solve(num, index + 1, output + "-" + num[index], target);
        solve(num, index + 1, output + "*" + num[index], target);
        solve(num, index + 1, output + num[index], target);
    }
    vector<string> addOperators(string num, int target) {
        solve(num, 1, to_string(num[0]-'0'), target);
        return ans;
    }
};