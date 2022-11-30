// Written by: Jian-Yuan Lin
// Date: 2022.11.30

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        for (int i = 0; i < intervals.size(); i++){
            // not overlapped, new interval is in the left, insert and copy the rest
            if (newInterval[1] < intervals[i][0]){
                ans.push_back(newInterval);
                for (int j = i; j < intervals.size(); j++){
                    ans.push_back(intervals[j]);
                }
                return ans;
            }
            // not overlapped, new interval is in the right, insert the current interval
            else if (newInterval[0] > intervals[i][1]){
                ans.push_back(intervals[i]);
            }
            else{
                // overlapped, update the newInterval
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }
        // if reach here, that means new interval is to be inserted at the end
        ans.push_back(newInterval);
        return ans;
    }
};