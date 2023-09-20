#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findInterSection(vector<int>& i1, vector<int>& i2) {
        return {max(i1[0], i2[0]), min(i1[1], i2[1])};
    }
    bool interSectionPresent(vector<int>& i1, vector<int>& i2) {
        return min(i1[1], i2[1]) - max(i1[0], i2[0]) >= 0;
    }
    vector<vector<int>> findIntervalIntersections(vector<int>& interval, vector<vector<int>>& secondList) {
        int n = secondList.size();
        if(n == 0) return {};

        vector<vector<int>> result; 

        int startIndex = lower_bound(secondList.begin(), secondList.end(), interval) - secondList.begin();
        if(startIndex > 0) {
            if(interSectionPresent(interval, secondList[startIndex-1])) {
                result.push_back(findInterSection(interval, secondList[startIndex-1]));
            }
        }
        while(startIndex < n && interSectionPresent(interval, secondList[startIndex])) {
            result.push_back(findInterSection(interval, secondList[startIndex]));
            startIndex++;
        }
        return result;

    }
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> result;
        for(vector<int>& interval: firstList) {
            vector<vector<int>> intervalIntersections = findIntervalIntersections(interval, secondList);
            for(vector<int> intersections: intervalIntersections) {
                result.push_back(intersections);
            }
        }
        return result;
        
    }
};

int main() {
    vector<vector<int>> fL = {{0, 2}, {5, 10}, {13, 23}, {24, 25}};
    vector<vector<int>> sL = {{1, 5}, {8, 12}, {15, 24}, {25, 26}};
    Solution s;
    vector<vector<int>> ans = s.intervalIntersection(fL, sL);
    for(vector<int>& row: ans) {
        for(int e: row) cout << e <<  ", ";
        cout << endl;
    }
    return 0;
}