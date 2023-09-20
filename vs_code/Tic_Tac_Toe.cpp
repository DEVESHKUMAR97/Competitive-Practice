#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define casenum cout << "Case " << ++tt << ": "
#define endl '\n'
using namespace std;

void print(vector< vector<int> > &a, int n, int m) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << "============================\n";
}


// Reference Link: https://www.geeksforgeeks.org/smallest-element-from-all-square-submatrices-of-size-k-from-a-given-matrix/

int matrixMax(vector<vector<int> > nums, int K)
{

  int N = nums.size();
  int M = nums[0].size();
 vector<vector<int> > res(N - K + 1, vector<int>(M - K + 1));
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M - K + 1; j++)
    {
      int mini = INT_MIN;
      for (int k = j; k < j + K; k++)
      {
        mini = max(mini, nums[i][k]);
      }
      nums[i][j] = mini;
    }
  }
 
  // Update the minimum column-wise
  for (int j = 0; j < M; j++)
  {
    for (int i = 0; i < N - K + 1; i++)
    {
      int mini = INT_MIN;
      for (int k = i; k < i + K; k++)
      {
        mini = max(mini, nums[k][j]);
      }
      nums[i][j] = mini;
    }
  }

  int ans = INT_MAX;
 
  // Store the final submatrix with
  // required minimum values
  for (int i = 0; i < N - K + 1; i++)
    for (int j = 0; j < M - K + 1; j++)
      ans = min(ans, nums[i][j]);
 
  // Return the resultant matrix
  return ans;
}

 
int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(10);
 
    int t;
    cin >> t;
    while(t--){
        
        int n, m, k;
        cin >> n >> m >> k;

        // int a[n+1][m+1];
        // int b[n+1][m+1];
        
        // int aTime[n+1][m+1];
        // int bTime[n+1][m+1];

        // int aTimeFinal[n+1][m+1];
        // int bTimeFinal[n+1][m+1];

        vector< vector<int> > a(n+1, vector<int>(m+1));
        vector< vector<int> > b(n+1, vector<int>(m+1));
        vector< vector<int> > aTime(n+1, vector<int>(m+1));
        vector< vector<int> > bTime(n+1, vector<int>(m+1));
        vector< vector<int> > aTimeFinal(n+1, vector<int>(m+1));
        vector< vector<int> > bTimeFinal(n+1, vector<int>(m+1));

        

        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= m; j++) {
                a[i][j] = 0;
                b[i][j] = 0;
                aTime[i][j] = 1e6;
                bTime[i][j] = 1e6;
                aTimeFinal[i][j] = 1e6;
                bTimeFinal[i][j] = 1e6;

            }
        }

        int i, j;
        for(int ii = 0; ii < n * m; ii++) {
            cin >> i >> j;
            if(ii & 1) {
                b[i][j] = 1;
                bTime[i][j] = ii;
            } else {
                a[i][j] = 1;
                aTime[i][j] = ii;
            }
        }

        // cout << "a:" << endl;
        // print(a, n, m);

        
        // cout << "b:" << endl;
        // print(b, n, m);

        
        // cout << "aTime:" << endl;
        // print(aTime, n, m);

        
        // cout << "bTime:" << endl;
        // print(bTime, n, m);
        
        

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(a[i][j] == 1) {
                    a[i][j] = min(min(a[i-1][j], min(a[i-1][j-1], a[i][j-1])) + 1, k);
                }
                if(b[i][j] == 1) {
                    b[i][j] = min(min(b[i-1][j], min(b[i-1][j-1], b[i][j-1])) + 1, k);
                }
            }
        }

        // cout << "a:" << endl;
        // print(a, n, m);

        
        // cout << "b:" << endl;
        // print(b, n, m);



        int aliceMin = 1e9;
        int bobMin = 1e9;
        int tempMax = -1e9;
        bool winnerFound = false;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(a[i][j] == k) {
                    winnerFound = true;
                    // tempMax = -1e9;
                    // for(int x = i - k + 1; x <= i; x++) {
                    //     for(int y = j - k + 1; y <= j; y++) {
                    //         tempMax = max(tempMax, aTime[x][y]);
                    //     }
                    // }
                    // aliceMin = min(tempMax, aliceMin);

                    // cout << tempMax << "#############" << endl;
                }


                if(b[i][j] == k) {
                    winnerFound = true;
                    // tempMax = -1e9;
                    // for(int x = i - k + 1; x <= i; x++) {
                    //     for(int y = j - k + 1; y <= j; y++) {
                    //         tempMax = max(tempMax, bTime[x][y]);
                    //     }
                    // }
                    // bobMin = min(tempMax, bobMin);

                    // cout << tempMax << "#############" << endl;
                }
            }
        }

        aliceMin = matrixMax(aTime, k);
        bobMin = matrixMax(bTime, k);

        // cout << aliceMin << " " << bobMin << endl;


        if(winnerFound == false) cout << "Draw" << endl;
        else if(aliceMin < bobMin) cout << "Alice" << endl;
        else cout << "Bob" << endl;

        // // 0=> _alice 
        // // 1=> Bob

        // int i, j;
        // int minn;
        
        // for(int ii = 0; ii < n * m; ii++) {
        //     cin >> i >> j;
            
        //     if(winnerFound == true) continue;

        //     minn = min(a[i-1][j], min(a[i-1][j-1], a[i][j-1]));
        //     a[i][j] = minn + 1;

        //     if(a[i][j] == k) {
        //         if(ii & 1) {
        //             cout << "Bob" << endl;
        //         } else {
        //             cout << "Alice" << endl;
        //         }
        //         winnerFound = true;
        //     }
        // }
        // if(winnerFound == false) cout << "Draw\n";
    }
    return 0;
}