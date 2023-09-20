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

    // map<pair<int, int>, int, MyComp> mp;
    // mp[{3, -1}] = 100;
    // mp[{-1, 100}] = 200;
    // mp[{-1, 20}] = 500;
    // mp[{0, 1}] =  50;
    // mp[{5, -100}] = 2;

    // for(auto &e: mp) {
    //     cout << "{" << e.first.first << ", " << e.first.second << "}" << " => " << e.second << endl;
    // }


    map<int, int> temp, temp2, temp3;
    temp[3] = 1;
    temp[2] = 2;
    temp[1] = 3;

    temp2[3] = 1;
    temp2[2] = 2;
    temp2[1] = 1;

    temp3[0] = 100;
    temp3[7] = 9;


    map<map<int, int>, int> mp2;
    mp2[temp] = 1;
    mp2[temp2] = 2;
    mp2[temp3] = 1;

    for(auto &e : mp2) {
        printMap(e.first);
        cout << e.second << endl;
    }
 
    
    return 0;
}

// {-1, 20} => 500
// {-1, 100} => 200
// {0, 1} => 50
// {3, -1} => 100
// {5, -100} => 2


// {-1, 100} => 200
// {-1, 20} => 500
// {0, 1} => 50
// {3, -1} => 100
// {5, -100} => 2



























