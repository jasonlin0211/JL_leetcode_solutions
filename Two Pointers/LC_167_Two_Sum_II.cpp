// Written by: Jian-Yuan Lin
// Date: 2022.11.17

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // use two pointers, this can be extended to kSum!
        vector<int> ans;
        int i = 0, j = numbers.size() - 1;
        while (true){
            int cur = numbers[i] + numbers[j];
            if (cur == target){
                ans.push_back(i+1);
                ans.push_back(j+1);
                break;
            }
            else if (cur > target){
                j--;
            }
            else{
                i++;
            }
        }
        return ans;
    }
};