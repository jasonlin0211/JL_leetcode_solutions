// Written by: Jian-Yuan Lin
// Date: 2023.01.26

class Solution {
public:
    bool dp(string& w, unordered_set<string>& seen, unordered_map<string, bool>& mem){
        if (mem.count(w)){
            return mem[w];
        }
        mem[w] = false;
        for (int i = 1; i < w.size(); i++){
            string first = w.substr(0, i);
            string second = w.substr(i);
            if ((seen.count(first) && seen.count(second)) || (seen.count(first) && dp(second, seen, mem))){
                mem[w] = true;
                return mem[w];
            }
        }
        return mem[w];
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> seen;
        for (string w: words){
            seen.insert(w);
        }
        unordered_map<string, bool> mem;
        vector<string> ans;
        for (string w: words){
            if (dp(w, seen, mem)){
                ans.push_back(w);
            }
        }
        return ans;
    }
};