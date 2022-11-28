// Written by: Jian-Yuan Lin
// Date: 2022.11.17

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;

        for (string str: strs){
            string s = str;
            sort(s.begin(), s.end());
            map[s].push_back(str);
        }
        vector<vector<string>> ans;
        for (auto it = map.begin(); it != map.end(); it++){
            ans.push_back(it->second);
        }
        return ans;
    }
};