// Written by: Jian-Yuan Lin
// Date: 2022.11.17

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> l_max(n, 0), r_max(n, 0);
        // find the left max for every idx
        for(int i = 1; i < n; i++){
            l_max[i] = max(l_max[i-1], height[i-1]);
        }
        // find the right max for every idx
        for(int i = n-2; i >= 0; i--){
            r_max[i] = max(r_max[i+1], height[i+1]);
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            int h = min(l_max[i], r_max[i]);
            // make sure the min height from two side is larger than the height @ idx
            if ((h - height[i]) > 0){
                ans += h - height[i];
            }
        }
        return ans;
    }
};