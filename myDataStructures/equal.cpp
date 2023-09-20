vector<int> Solution::equal(vector<int> &A) {
    int n = A.size();
    
    unordered_map<int, pair<int, int> > ump;
    
    vector< vector<int> > bigAns;
    
    int sum;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            sum = A[i] + A[j];
            if(ump.find(sum) != ump.end()) {
                pair<int, int> pp =  ump[sum];
                if(pp.first < i && pp.second != i && pp.second != j) {
                    vector<int> ans(4);
                    ans[0] = pp.first;
                    ans[1] = pp.second;
                    ans[2] = i;
                    ans[3] = j;
                    bigAns.push_back(ans);
                }
            }
            if(ump.find(sum) == ump.end()) {
                ump.insert({sum, make_pair(i, j)});
            }
            
        }
    }
    
    sort(bigAns.begin(), bigAns.end());
    if(bigAns.size() == 0) {
        vector<int> ans;
        return ans;
    } else {
        return bigAns[0];
    }
}
//A : [ 1, 3, 3, 3, 3, 2, 2 ]

// your: 1 5 2 6 
// expected: 0 1 5 6 
// 0,2 & 1,3 - A: 3 5 4 2 , 0 1 2 3 -> 3 5 4 2



// 3 -3 3

// ump[0] = {0, 1}
// sum = 0 , {1, 2}

// 1 3 1 3

// am i audible?
// Sorry got a call.. give me a minute
// okh no problem