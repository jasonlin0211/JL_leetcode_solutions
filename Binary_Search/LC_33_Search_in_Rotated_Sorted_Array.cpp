// Written by: Jian-Yuan Lin
// Date: 2022.11.20

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while (l < r){
            int mid = l + (r-l)/2;
            if (nums[mid] == target){
                return mid;
            }
            // left part is sorted in ascending order, so we can easily check if target is in this range
            if (nums[l] < nums[mid]){
                if (nums[l] <= target && target < nums[mid]){
                    r = mid;
                }
                else{
                    l = mid + 1;
                }
            }
            // pivot point is in the left part, so the right part is sorted in ascending order, so we can easily check if target is in this range
            else{
                if (nums[mid] < target && target <= nums[r-1]){
                    l = mid + 1;
                }
                else{
                    r = mid;
                }
            }
        }
        return -1;   
    }
};