// Written by: Jian-Yuan Lin
// Date: 2022.12.05

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // practice heap based solution now, try quick select later
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int num: nums){
            pq.push(num);
            if (pq.size() > k){
                pq.pop();
            }
        }
        return pq.top();
    }
};