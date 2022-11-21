// Written by: Jian-Yuan Lin
// Date: 2022.11.20

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end()) + 1;

        while (l < r){
            int mid = l + (r-l)/2;
            if (can_finish(piles, mid, h)){
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }
        return l;
    }
private:
    bool can_finish(vector<int>& nums, int v, int h){
        int total = 0;
        for (int num: nums){
            total += (num + v - 1) / v;
        }
        if (total <= h){
            return true;
        }
        return false;
    }
};