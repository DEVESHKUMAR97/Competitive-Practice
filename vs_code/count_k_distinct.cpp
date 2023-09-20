#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    int k; 
    cin >> k;
    
    map<char, int> mps, mpb;
    int i = 0, js = 0, jb = 0;
    
    int ans = 0;
    
    while(true) {
        bool f1 = false, f2 = false, f3 = false;
        
        while(jb < n) {
            mpb[s[jb]]++;
            if(mpb.size() == k + 1) {
                mpb[s[jb]]--;
                if(mpb[s[jb]] == 0) {
                    mpb.erase(s[jb]);
                }
                jb--;
                break;
            }
            jb++;
            f1 = true;
        }
        
        while(js < jb) {
            mps[s[js]]++;
            if(mps.size() == k) {
                mps[s[js]]--;
                if(mps[s[js]] == 0) {
                    mps.erase(s[js]);
                }
                js--;
                break;
            }
            js++;
            f2 = true;
        }
        
        
        while(i < js) {
            if(mpb.size() == k && mps.size() == k - 1) {
                ans += jb - js + 1;
            }
            
            mpb[s[i]]--;
            if(mpb[s[i]] == 0) {
                mpb.erase(s[i]);
            }
            mps[s[i]]--;
            if(mps[s[i]] == 0) {
                mps.erase(s[i]);
            }
            i++;
            
            if(mpb.size() != k || mps.size() != k - 1) {
                break;
            }
            
            f3 = true;
        }
        
        if(f1 == false && f2 == false && f3 == false) break;
    }
    
    cout << ans << endl;
}


















