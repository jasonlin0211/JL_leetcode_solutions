// Written by: Jian-Yuan Lin
// Date: 2022.11.30

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1){
            return true;
        }
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b){
            return a[0] < b[0];
        });
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++){
            if (res.back()[1] > intervals[i][0]){
                return false;
            }
            res.push_back(intervals[i]);
        }
        return true;
    }
};