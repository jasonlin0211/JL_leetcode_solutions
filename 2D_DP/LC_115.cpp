// Written by: Jian-Yuan Lin
// Date: 2023.01.08

class Solution {
public:
    int dp(int i, int j, string& s, string& t, unordered_map<int, unordered_map<int, int>>& mem){
        if (j == t.size()){
            return 1;
        }
        if (i == s.size()){
            return 0;
        }
        if (mem.count(i) && mem[i].count(j)){
            return mem[i][j];
        }
        mem[i][j] = 0;
        if (s[i] == t[j]){
            mem[i][j] = dp(i+1, j+1, s, t, mem) + dp(i+1, j, s, t, mem);
        }
        else{
            mem[i][j] = dp(i+1, j, s, t, mem);
        }
        return mem[i][j];
    }
    int numDistinct(string s, string t) {
        // try top down DP first, very similar to LC 97 interleaving string
        unordered_map<int, unordered_map<int, int>> mem;
        return dp(0, 0, s, t, mem);
    }
};