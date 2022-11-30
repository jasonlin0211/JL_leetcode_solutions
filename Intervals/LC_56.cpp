// Written by: Jian-Yuan Lin
// Date: 2022.11.30

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 1){
            return intervals;
        }
        // learn to use the lambda function here, important
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b){
            return a[0] < b[0]; // sort ascending based on the intervals[i][0]
        });
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++){
            if (is_overlap(ans.back(), intervals[i])){
                vector<int> newInterval = {min(ans.back()[0], intervals[i][0]), max(ans.back()[1], intervals[i][1])};
                ans.pop_back();
                ans.push_back(newInterval);
            }
            else{
                ans.push_back(intervals[i]);
            }
        }
        return ans;   
    }
private:
    bool is_overlap(vector<int>& l1, vector<int>& l2){
        return l1[1] >= l2[0];
    }
};