#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define casenum cout << "Case " << ++tt << ": "
#define endl '\n'
using namespace std;

void printVector(vector<int>& a) {
    for(int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

class MyComp {
    public:
        bool operator()(const pair<int, int>& below, const pair<int, int>& above) {
            if(below.first > above.first) {
                return true;
            } else if(below.first < above.first) {
                return false;
            } else {
                return below.second < above.second;
            }
        }
};
 
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
 
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> A(n);
        priority_queue<pair<int, int> , vector<pair<int, int> >, MyComp  > minHeap;
        for(int i = 0; i < n ;i++) {
            cin >> A[i];
            if(i >= k) {
                minHeap.push({A[i], i});
            }
        }
        for(int i = 0; i < n; i++) {
            while(minHeap.size() > 0 && i + k > minHeap.top().second) {
                minHeap.pop();
            }
            if(minHeap.size() > 0 && A[i] > minHeap.top().first) {
                pair<int, int> c = minHeap.top(); minHeap.pop();
                minHeap.push({A[i], c.second});
                swap(A[i], A[c.second]);
            }
        }
        printVector(A);

        
    }
    return 0;
}
