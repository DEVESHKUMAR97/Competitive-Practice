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

bool isValid(vector<int>& a) {
    for(int i = 0; i < a.size() - 2; i++) {
        int a2 = 3 * a[i+2];
        if(a2 % (a[i] + a[i+1]) == 0) {
            return false;
        }
    }
    return true;
}
 
int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(10);
 
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a;
        for(int i = 5; i <= n + 4; i++) {
            a.push_back(i);
        }
        printVector(a);
 
        
    }
    return 0;
}