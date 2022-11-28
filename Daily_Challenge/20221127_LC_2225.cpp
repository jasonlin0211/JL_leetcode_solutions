// Written by: Jian-Yuan Lin
// Date: 2022.11.27

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans(2);
        unordered_set<int> seen;
        unordered_map<int, vector<int>> count;
        int max_value = 0;
        for (int i = 0; i < matches.size(); i++){
            int winner = matches[i][0], loser = matches[i][1];
            count[loser].push_back(winner);
            seen.insert(winner);
            seen.insert(loser);
            max_value = max(max_value, max(winner, loser));
        }
        for (int i = 1; i <= max_value; i++){
            if (!seen.count(i)){
                continue;
            }
            if (!count.count(i)){
                ans[0].push_back(i);
            }
            else if (count[i].size() == 1){
                ans[1].push_back(i);
            }
        }
        return ans;
    }
};