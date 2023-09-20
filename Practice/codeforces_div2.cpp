#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;
 

int main() {
  // your code goes here

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
//   #ifndef ONLINE_JUDGE
//   freopen("input.txt", "r", stdin);
//   freopen("output.txt", "w", stdout);
//   freopen("error.txt", "w", stderr);
//   #endif

  int t;
  cin >> t;
  while(t--){
      int n, m;
      cin >> n >> m;
      int r[n];
      for(int i = 0; i < n; i++){
        cin >> r[i];
      }
      int changes[n][m];
      int p_rating[n] = {0};
      int p_rank[n];
      for(int  i = 0; i < n; i++){
        p_rank[i] = 1e5;
      }
      int p_rank_m[n] = {0};
      int p_rating_m[n] = {0};
      for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
          cin >> changes[i][j];
        }
      }
      vector < pair <int, int> > vec;

      int rank = 0;
      int prev_rate;
      for(int j = 0; j < m; j++){

        vec.clear();

        for(int i  = 0; i < n; i++){
          r[i] += changes[i][j];
          vec.push_back(make_pair(r[i], i));
          if(r[i] > p_rating[i]){
            p_rating[i] = r[i];
            p_rating_m[i] = j + 1;
          }
        }

        sort(vec.begin(), vec.end(), greater <pair <int, int> > ());

        rank = 0;
        prev_rate = vec[0].first;
        for(int i = 0; i < vec.size(); i++){
          if(prev_rate != vec[i].first){
            rank = i;
            prev_rate = vec[i].first;
          }
          if(p_rank[vec[i].second] > rank){
            p_rank[vec[i].second] = rank;
            p_rank_m[vec[i].second] = j + 1;
          }
          
        }


      }
      int ans = 0;
      for(int i = 0; i < n; i++){
        if(p_rank_m[i] != p_rating_m[i]){
          ans++;
        }
      }
      cout << ans << endl;

  }
  return 0;
}  



