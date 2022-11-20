// Written by: Jian-Yuan Lin
// Date: 2022.11.19

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0){
            return {};
        }
        mapping.insert({'2', {'a', 'b', 'c'}});
        mapping.insert({'3', {'d', 'e', 'f'}});
        mapping.insert({'4', {'g', 'h', 'i'}});
        mapping.insert({'5', {'j', 'k', 'l'}});
        mapping.insert({'6', {'m', 'n', 'o'}});
        mapping.insert({'7', {'p', 'q', 'r', 's'}});
        mapping.insert({'8', {'t', 'u', 'v'}});
        mapping.insert({'9', {'w', 'x', 'y', 'z'}});
        vector<string> ans;
        string cur; 
        dfs(digits, 0, cur, ans);
        return ans;
    }
private:
    unordered_map<char, vector<char>> mapping;
    void dfs(string digits, int i, string cur, vector<string>& ans){
        if (cur.size() == digits.size()){
            ans.push_back(cur);
            return;
        }
        for (char c : mapping[digits[i]]){
            cur += c;
            dfs(digits, i+1, cur, ans);
            cur.pop_back();
        }
    }
};