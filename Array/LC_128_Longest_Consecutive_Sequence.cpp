// Written by: Jian-Yuan Lin
// Date: 2022.11.17

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seen(nums.begin(), nums.end());
        /*
        unordered_set<int> seen;
        for (int num: nums){
            seen.insert(num);
        }*/
        int max_length = 0;
        for (int num : nums){
            if (seen.count(num-1)){
                continue;
            }
            int curlen = 1;
            while (seen.count(num + curlen)){
                curlen += 1;
            }
            max_length = max(max_length, curlen);
        }
        
        return max_length;
    }
};