#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    cout << sum << endl;
    return 0;
}


// 101628856475
// BG BNG 0026858 000 0246107
// GN GGN 0033971 000 0011385
