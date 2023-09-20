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
    
    int n;
    cin >> n;
    int a[n+1];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int prev = 1;
    vector< pair<int, int> > ans;
    for(int i = n; i > 0; i--){
        if(a[i] == 1){
            
        } else if(a[i] == 2){

        } else if(a[i] == 3){

        }
    }
    return 0;
}