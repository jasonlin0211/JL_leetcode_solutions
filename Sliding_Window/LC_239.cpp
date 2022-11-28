// Written by: Jian-Yuan Lin
// Date: 2022.11.28

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // C++ has the same data structure for deque!
        deque<int> q;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++){
            while (!q.empty() && q.back() < nums[i]){
                q.pop_back();
            }
            q.push_back(nums[i]);
            if (i-k+1 >= 0){
                ans.push_back(q.front());
                if (nums[i-k+1] == q.front()){
                    q.pop_front();
                }
            }
        }
        return ans;
    }
};