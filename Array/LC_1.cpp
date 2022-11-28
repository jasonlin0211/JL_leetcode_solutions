// Written by: Jian-Yuan Lin
// Date: 2022.11.17

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++){
            int complement = target - nums[i];
            if (map.count(complement)){
                ans = {i, map[complement]};
                break;
            }
            map.insert({nums[i], i});
            //map[nums[i]] = i;
        }
        return ans;
    }
};