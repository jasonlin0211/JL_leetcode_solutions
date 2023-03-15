class Solution {
public:
    int cal(vector<int>& nums){
        int res = 0;
        for (int i = 0; i < nums.size(); i++){
            res = res * 10 + nums[i];
        }
        return res;
    }

    int splitNum(int num) {
        vector<int> nums;
        while (num){
            nums.push_back(num % 10);
            num /= 10;
        }
        sort(nums.begin(), nums.end());
        vector<int> n1, n2;
        for (int i = 0; i < nums.size(); i++){
            if (i % 2 == 0){
                n1.push_back(nums[i]);
            }
            else{
                n2.push_back(nums[i]);
            }
        }
        return cal(n1) + cal(n2);
    }
};