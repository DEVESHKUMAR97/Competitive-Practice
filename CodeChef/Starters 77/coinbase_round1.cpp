#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define casenum cout << "Case " << ++tt << ": "
#define endl '\n'
using namespace std;

class MyComp {
    public:
    bool operator()(pair<int, int> a, pair<int, int> b) const {
        if(a.first < b.first) return true;
        if(a.first > b.first) return false;
        return a.second > b.second;
    }
};

void printMap(map<int, int> mp) {
    for(auto &e: mp) {
        cout << e.first << "-" << e.second << " # ";
    }
    cout << " => ";
}
 
int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(10);

    
    return 0;
}



// 50

























