
#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define casenum cout << "Case " << ++tt << ": "
#define endl '\n'
using namespace std;

void printIncreasingSet(set<int>& s) {
    for(int num: s) {
        cout << num << ", ";
    }
    cout << endl;
}

void printDecreasingSet(set<int, greater<int>>& s) {
    for(int num: s) {
        cout << num << ", ";
    }
    cout << endl;
}
 
int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(10);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // freopen("error.txt", "w", stderr);
    // #endif
 
    set<int> s1;
    s1.insert(2);
    s1.insert(5);
    s1.insert(1);
    s1.insert(9);
    printIncreasingSet(s1);
    set<int>::iterator itr1 = lower_bound(s1.begin(), s1.end(), 2);
    cout << "lower_bound(2) = "  << *itr1 << endl;
    // cout << "index = " << lower_bound(s1.begin(), s1.end(), 2) - s1.begin() << endl;  // error indexing is not defined in the set
    itr1 = lower_bound(s1.begin(), s1.end(), 3);
    cout << "lower_bound(3) = "  << *itr1 << endl;

    itr1 = upper_bound(s1.begin(), s1.end(), 2);
    cout << "upper_bound(2) = "  << *itr1 << endl;
    itr1 = upper_bound(s1.begin(), s1.end(), 3);
    cout << "upper_bound(3) = "  << *itr1 << endl;

    itr1--; // iterator increment and decrement in possible
    cout << "itr-- = " << *itr1 << endl; 
    --itr1;
    cout << "itr-- = " << *itr1 << endl; 

    cout << "=====================\n";

    set<int, greater<int>> s2;
    s2.insert(2);
    s2.insert(5);
    s2.insert(1);
    s2.insert(9);
    printDecreasingSet(s2);
    set<int, greater<int>>::iterator itr2 = lower_bound(s2.begin(), s2.end(), 5, greater<int>());
    cout << "lower_bound(5) = "  << *itr2 << endl;
    itr2 = lower_bound(s2.begin(), s2.end(), 3, greater<int>());
    cout << "lower_bound(3) = "  << *itr2 << endl;



    set<pair<int, int>> events;
    events.insert({1,2});
    events.insert({5, 9});
    auto itr3 = events.lower_bound({2, 3});
    
    return 0;
}