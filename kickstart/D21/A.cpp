#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define casenum cout << "Case " << ++tt << ": "
#define endl '\n'
using namespace std;

bool isAP(int a, int b, int c) {
    return b - a == c - b;
}
 
int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(10);
 
    int t;
    cin >> t;
    int tt = 0;
    while(t--){
        tt++;
        casenum;
        int mat[3][3];
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if( i == 1 && j == 1) {
                    mat[i][j] = 0;
                } else {
                    cin >> mat[i][j];
                }
            }
        }

        int cnt = 0;
        if(isAP(mat[0][0], mat[0][1], mat[0][2])) cnt++;
        if(isAP(mat[2][0], mat[2][1], mat[2][2])) cnt++;
        
        if(isAP(mat[0][0], mat[1][0], mat[2][0])) cnt++;
        if(isAP(mat[0][2], mat[1][2], mat[2][2])) cnt++;

        int cnt2 = 0;
        int temp = 0;
        if(isAP(mat[0][0], (mat[0][0] + mat[2][2]) / 2, mat[2][2])) temp++;
        if(isAP(mat[0][2], (mat[0][0] + mat[2][2]) / 2, mat[2][0])) temp++;      
        if(isAP(mat[0][1], (mat[0][0] + mat[2][2]) / 2, mat[2][1])) temp++;
        if(isAP(mat[1][0], (mat[0][0] + mat[2][2]) / 2, mat[1][2])) temp++;
        cnt2 = max(cnt2, temp);


        temp = 0;
        if(isAP(mat[0][0], (mat[0][2] + mat[2][0]) / 2, mat[2][2])) temp++;
        if(isAP(mat[0][2], (mat[0][2] + mat[2][0]) / 2, mat[2][0])) temp++;      
        if(isAP(mat[0][1], (mat[0][2] + mat[2][0]) / 2, mat[2][1])) temp++;
        if(isAP(mat[1][0], (mat[0][2] + mat[2][0]) / 2, mat[1][2])) temp++;
        cnt2 = max(cnt2, temp);


        temp = 0;
        if(isAP(mat[0][0], (mat[0][1] + mat[2][1]) / 2, mat[2][2])) temp++;
        if(isAP(mat[0][2], (mat[0][1] + mat[2][1]) / 2, mat[2][0])) temp++;      
        if(isAP(mat[0][1], (mat[0][1] + mat[2][1]) / 2, mat[2][1])) temp++;
        if(isAP(mat[1][0], (mat[0][1] + mat[2][1]) / 2, mat[1][2])) temp++;
        cnt2 = max(cnt2, temp);



        temp = 0;
        if(isAP(mat[0][0], (mat[1][0] + mat[1][2]) / 2, mat[2][2])) temp++;
        if(isAP(mat[0][2], (mat[1][0] + mat[1][2]) / 2, mat[2][0])) temp++;      
        if(isAP(mat[0][1], (mat[1][0] + mat[1][2]) / 2, mat[2][1])) temp++;
        if(isAP(mat[1][0], (mat[1][0] + mat[1][2]) / 2, mat[1][2])) temp++;
        cnt2 = max(cnt2, temp);

        cout << cnt + cnt2 << endl;

    }
    return 0;
}