// Written by: Jian-Yuan Lin
// Date: 2022.11.30

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1){
            return intervals.size();
        }
        
        sort(intervals.begin(), intervals.end());
        // learn how to use minheap in C++
        // type, container, comparator
        priority_queue<int, vector<int>, greater<int>> minheap;
        minheap.push(intervals[0][1]);
        for (int i = 1; i < intervals.size(); i++){
            if (minheap.top() <= intervals[i][0]){
                minheap.pop();
            }
            minheap.push(intervals[i][1]);
        }
        return minheap.size();
    }
};