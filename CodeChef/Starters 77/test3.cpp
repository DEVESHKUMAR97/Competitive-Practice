#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define casenum cout << "Case " << ++tt << ": "
#define endl '\n'
using namespace std;

double avg(int a,int b){
    return (a+b)/2.0;
}
double oddPresentInFirst(const vector<int> &A, const vector<int> &B) {
        int n = A.size();
        int m = B.size();
        int index = (n+m) / 2;
        int low = 0, high = n - 1;
        int mid;
        int mid2;
        while(low <= high) {
            mid = low + (high - low) / 2;
            mid2 = upper_bound(B.begin(), B.end(), A[mid]) - B.begin();
            if(mid + mid2 == index) {
                return (double) A[mid]; // tc 2
            }
            if(mid + mid2 < index) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1e9;
}
double evenPresentInFirst(const vector<int> &A, const vector<int> &B) {
        int n = A.size();
        int m = B.size();
        int index = (n+m) / 2;
        index--;
        int low = 0, high = n - 1;
        int mid;
        int mid2;
        while(low <= high) {
            mid = low + (high - low) / 2;
            mid2 = upper_bound(B.begin(), B.end(), A[mid]) - B.begin();
            if(mid + mid2 == index) {
                cout << "Hello\n";
                int temp;
                if(mid + 1 < n && mid2 < m) {
                    temp = min(A[mid+1], B[mid2]);
                } else if(mid + 1 < n) {
                    temp = A[mid+1];
                } else {
                    temp = B[mid2];
                }
                return avg(A[mid], temp); // tc 2
            }
            if(mid + mid2 < index) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1e9;
}

double solve(vector<int> &A, vector<int> &B) {
    int n = A.size();
        int m = B.size();
        int index = (n+m) / 2;
        if((n + m) % 2 != 0) {
            double ans = oddPresentInFirst(A,B);
            if(ans == -1e9) {
                ans = oddPresentInFirst(B, A);
            }
            return ans;
        } else {
            double ans = evenPresentInFirst(A,B);
            if(ans == -1e9) {
                ans = evenPresentInFirst(B, A);
            }
            return ans;
        }
}

 
int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(10);

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int m;
    cin >> m;
    vector<int> b(m);
    for(int i = 0; i < m; i++) cin >> b[i];
 
    cout << solve(a, b) << endl;
    return 0;
}