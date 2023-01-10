// Written by: Jian-Yuan Lin
// Date: 2023.01.09

class Solution {
public:
    bool dp(int i, int j, string& s, string& p, unordered_map<int, unordered_map<int, bool>>& mem){
        if (i >= s.size() && j >= p.size()){
            return true;
        }
        if (j >= p.size()){
            return false;
        }
        if (mem.count(i) && mem[i].count(j)){
            return mem[i][j];
        }
        
        bool match = false;
        if (i < s.size() && j < p.size() && (s[i] == p[j] || p[j] == '.')){
            match = true;
        }
        // deal with the * case
        if (j + 1 < p.size() && p[j + 1] == '*') {
            // choices: either (1) don't use *, or (2) use * only if match!
            mem[i][j] = dp(i, j + 2, s, p, mem) || (match && dp(i + 1, j, s, p, mem));
            return mem[i][j];
        }
        if (match) {
            mem[i][j] = dp(i + 1, j + 1, s, p, mem);
            return mem[i][j];
        }
        mem[i][j] = false;
        return mem[i][j];
    }
    bool isMatch(string s, string p) {
        // this is very difficult, top down DP + memoization
        unordered_map<int, unordered_map<int, bool>> mem;
        return dp(0, 0, s, p, mem);
    }
};