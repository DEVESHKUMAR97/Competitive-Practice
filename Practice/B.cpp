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
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif
    cout<<fixed<<setprecision(10);

    int king_row, king_col, queen_row, queen_col, queen_new_row, queen_new_col, king_pos, queen_pos,queen_new_pos;
    while(cin >> king_pos >> queen_pos >> queen_new_pos){
        king_row = king_pos / 8;
        king_col = king_pos % 8;
        queen_row = queen_pos / 8;
        queen_col = queen_pos % 8;
        queen_new_row = queen_new_pos / 8;
        queen_new_col = queen_new_pos % 8;

        if(king_row == queen_row && king_col == queen_col){
            cout << "Illegal state\n";
        } else if(queen_row == queen_new_row || queen_col == queen_new_col){
            
        }
    }
    return 0;
}  

// Problem link : https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=382
