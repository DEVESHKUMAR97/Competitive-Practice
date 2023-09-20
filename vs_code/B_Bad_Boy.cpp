#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define casenum cout << "Case " << ++tt << ": "
#define endl '\n'
using namespace std;

ll distFun(ll a, ll b, ll c, ll d) {
    return abs(a-c) + abs(b-d);
}
 
int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(10);
 
    int t;
    cin >> t;
    while(t--){
        ll n, m, i, j;
        cin >> n >> m >> i >> j;

        ll dist = -1;
        ll ansR1, ansC1, ansR2, ansC2;

        ll posR1 = 1, posC1 = 1, posR2 = 1, posC2 = m;
        ll currDist = distFun(i, j, posR1, posC1) + distFun(posR1, posC1, posR2, posC2) + distFun(posR2, posC2, i, j);
        // cout << currDist << "###########\n";
        if(dist < currDist) {
            dist = currDist;
            ansR1 = posR1;
            ansC1 = posC1;
            ansR2 = posR2;
            ansC2 = posC2;
        }


        posR1 = 1, posC1 = 1, posR2 = n, posC2 = m;
        currDist = distFun(i, j, posR1, posC1) + distFun(posR1, posC1, posR2, posC2) + distFun(posR2, posC2, i, j);
        // cout << currDist << "###########\n";
        if(dist < currDist) {
            dist = currDist;
            ansR1 = posR1;
            ansC1 = posC1;
            ansR2 = posR2;
            ansC2 = posC2;
            // cout << dist << "+++++++++++++++\n";
            
        }

        posR1 = 1, posC1 = 1, posR2 = n, posC2 = 1;
        currDist = distFun(i, j, posR1, posC1) + distFun(posR1, posC1, posR2, posC2) + distFun(posR2, posC2, i, j);
        // cout << currDist << "###########\n";
        if(dist < currDist) {
            dist = currDist;
            ansR1 = posR1;
            ansC1 = posC1;
            ansR2 = posR2;
            ansC2 = posC2;
            // cout << dist << "+++++++++++++++\n";
        }

        posR1 = 1, posC1 = m, posR2 = n, posC2 = m;
        currDist = distFun(i, j, posR1, posC1) + distFun(posR1, posC1, posR2, posC2) + distFun(posR2, posC2, i, j);
        // cout << currDist << "###########\n";
        if(dist < currDist) {
            dist = currDist;
            ansR1 = posR1;
            ansC1 = posC1;
            ansR2 = posR2;
            ansC2 = posC2;
            // cout << dist << "+++++++++++++++\n";
        }


        posR1 = 1, posC1 = m, posR2 = n, posC2 = 1;
        currDist = distFun(i, j, posR1, posC1) + distFun(posR1, posC1, posR2, posC2) + distFun(posR2, posC2, i, j);
        // cout << currDist << "###########\n";
        if(dist < currDist) {
            dist = currDist;
            ansR1 = posR1;
            ansC1 = posC1;
            ansR2 = posR2;
            ansC2 = posC2;
            // cout << dist << "+++++++++++++++\n";
        }

        posR1 = n, posC1 = m, posR2 = n, posC2 = 1;
        currDist = distFun(i, j, posR1, posC1) + distFun(posR1, posC1, posR2, posC2) + distFun(posR2, posC2, i, j);
        // cout << currDist << "###########\n";
        if(dist < currDist) {
            dist = currDist;
            ansR1 = posR1;
            ansC1 = posC1;
            ansR2 = posR2;
            ansC2 = posC2;
            // cout << dist << "+++++++++++++++\n";
        }




        // posR1 = 50, posC1 = 1, posR2 = 1, posC2 = m;
        // currDist = distFun(i, j, posR1, posC1) + distFun(posR1, posC1, posR2, posC2) + distFun(posR2, posC2, i, j);
        // cout << currDist << "###########\n";
        // cout << dist << "&&&&&&&&&&&&&&&\n";
        // if(dist < currDist) {
        //     dist = currDist;
        //     ansR1 = posR1;
        //     ansC1 = posC1;
        //     ansR2 = posR2;
        //     ansC2 = posC2;
        //     // cout << dist << "+++++++++++++++\n";
        // }


        cout << ansR1 << " " << ansC1 << " " << ansR2 << " " << ansC2 << endl;
    }
    return 0;
}