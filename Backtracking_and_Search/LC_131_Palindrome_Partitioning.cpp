// Written by: Jian-Yuan Lin
// Date: 2022.11.19

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        dfs(s, curr, ans);
        return ans;
    }
private:
    bool is_palid(string s){
        int l = 0, r = s.size() - 1;
        while(l < r){
            if (s[l] != s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    void dfs(string s, vector<string>& curr, vector<vector<string>>& ans){
        if (s.size() == 0){
            ans.push_back(curr);
            return;
        }
        for (int l = 1; l <= s.size(); l++){
            string first = s.substr(0, l), second = s.substr(l);
            //cout << first <<" " << second << endl;
            if (is_palid(first)){
                curr.push_back(first);
                dfs(second, curr, ans);
                curr.pop_back();
            }
        }


    }
};