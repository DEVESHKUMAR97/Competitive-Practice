#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define casenum cout << "Case " << ++tt << ": "
#define endl '\n'
using namespace std;
 
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
        int arr[n];
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        int i = 1;
        int level = 1;
        int nodes_left_in_layer = 1, nodes_in_next_layer = 1;
        while(i < n - 1){
            if(arr[i] < arr[i+1]){
                nodes_in_next_layer++;
            } else{
                nodes_left_in_layer--;
                // i--;
            }
            if(nodes_left_in_layer == 0){
                level++;
                nodes_left_in_layer = nodes_in_next_layer;
                nodes_in_next_layer = 0;
            }
            i++;
        }
        cout << level<< endl;
    }
    return 0;
}