#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define casenum cout << "Case " << ++tt << ": "
#define endl '\n'
using namespace std;

ll grid[1001][1001];
int ROW = 3;
int COL = 3;


void generateGrid() {
    int val = 1;
    

    for (int line=1; line<=(ROW + COL -1); line++)
    {
        /* Get column index of the first element
           in this line of output.
           The index is 0 for first ROW lines and
           line - ROW for remaining lines  */
        int start_col =  max(0, line-ROW);
 
        /* Get count of elements in this line. The
           count of elements is equal to minimum of
           line number, COL-start_col and ROW */
         int count = min(line, min(COL-start_col, ROW));
 
        /* Print elements of this line */
        for (int j=0; j<count; j++)
                   grid[min(ROW, line)-j-1][start_col+j] = val;
        val++;
    }
}

void printGrid() {
    for(int i = 1; i <= ROW; i++) {
        for(int j = 1; j <= COL; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}
 
int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(10);

    generateGrid();
    printGrid();
 
    int t;
    cin >> t;
    while(t--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
    }
    return 0;
}