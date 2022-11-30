// Written by: Jian-Yuan Lin
// Date: 2022.11.30

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() == 1){
            return 0;
        }
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b){
            return a[0] < b[0];  
        });
        int ans = 0;
        vector<vector<int>> result;
        result.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++){
            if (is_overlap(result.back(), intervals[i])){
                ans++;
                // since two intervals are overlapped, we want to make the end
                // to be smaller one, so we could reduce the cut in the future
                result.back()[1] = min(result.back()[1], intervals[i][1]);
                continue;
            }
            else{
                result.push_back(intervals[i]);
            }
        }
        return ans;
    }
private:
    bool is_overlap(vector<int>& l1, vector<int>& l2){
        return l1[1] > l2[0];
    }
};