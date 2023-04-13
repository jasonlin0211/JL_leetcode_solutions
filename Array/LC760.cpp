class Solution {
public:
    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, vector<int>> pos;
        for (int i = 0; i < nums2.size(); i++){
            pos[nums2[i]].push_back(i);
        }
        vector<int> ans;
        for (int num: nums1){
            int idx = pos[num].back();
            pos[num].pop_back();
            ans.push_back(idx);
        }
        return ans;
    }
};