
#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define casenum cout << "Case " << ++tt << ": "
#define endl '\n'
using namespace std;

template <typename T>
void printVector(vector<T>& a) {
    for(int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

template <typename T>
void printMap(map<T, T>& mp) {
    for(auto& e: mp) {
        cout << e.first << " => " << e.second << endl;
    }
}

class Box {
    public:
    int x;
    Box(int val) {
        x = val;
    }
    Box() {
        
    }
};
 
int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(10);
    
    map<int, int> mp;
    mp[1] = 10;
    mp[2] = 12;
    printMap(mp);

    Box b(23);
    map<int, Box> mp2;
    mp2[2] = b;
    cout << mp2.begin()->first << ", " << mp2.begin()->second.x;

    return 0;
}
