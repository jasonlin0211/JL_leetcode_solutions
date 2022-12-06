// Written by: Jian-Yuan Lin
// Date: 2022.12.06

class Solution {
public:
    bool dp(string s, unordered_map<string, bool>& mem, unordered_set<string>& seen){
        if (mem.count(s)){
            return mem[s];
        }
        if (seen.count(s)){
            mem[s] = true;
            return mem[s];
        }
        // split the word 
        mem[s] = false;
        for (int i = 1; i < s.size(); i++){
            string first = s.substr(0, i);
            string second = s.substr(i, s.size() - i);
            if (dp(first, mem, seen) && seen.count(second)){
                mem[s] = true;
                break;
            }
        }
        return mem[s];
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, bool> mem;
        mem[""] = true;
        unordered_set<string> seen(wordDict.begin(), wordDict.end());

        return dp(s, mem, seen);
    }
};