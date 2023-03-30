class Solution {
public:
    vector<int> cal_freq(string s){
        vector<int> ans(26, 0);
        for (char c: s){
            ans[c - 'a']++;
        }
        return ans;
    }
    bool scramble(string s1, string s2, unordered_map<string, unordered_map<string, bool>>& mem){
        if (s1 == s2){
            return true;
        }
        if (mem.count(s1) && mem[s1].count(s2)){
            return mem[s1][s2];
        }
        if (cal_freq(s1) != cal_freq(s2)){
            mem[s1][s2] = false;
            return false;
        }
        mem[s1][s2] = false;
        int L = s1.size();
        for (int i = 1; i < L; i++){
            if (scramble(s1.substr(0, i),s2.substr(0, i), mem) && scramble(s1.substr(i), s2.substr(i), mem)){
                mem[s1][s2] = true;
                return true;
            }
            if (scramble(s1.substr(0, i), s2.substr(L-i, i), mem) && scramble(s1.substr(i), s2.substr(0, L-i), mem)){
                mem[s1][s2] = true;
                return true;
            }
        }
        return mem[s1][s2];
    }
    bool isScramble(string s1, string s2) {
        // without memoization it will TLE
        unordered_map<string, unordered_map<string, bool>> mem;
        return scramble(s1, s2, mem);
    }

};