// Written by: Jian-Yuan Lin
// Date: 2022.11.28

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> s_count, t_count;
        for (char ch : t){
            t_count[ch]++;
        }
        int need = t_count.size(); // how many unique chars
        int have = 0;
        int start = 0, ans_len = INT_MAX;
        int l = 0;
        for (int r = 0; r < s.size(); r++){
            s_count[s[r]]++;
            if (t_count.count(s[r]) && s_count[s[r]] == t_count[s[r]]){
                have += 1;
            }
            // keep shrinking the left pointer to make the substring minimal
            while (have == need){
                // update the answer first
                int cur_len = r - l + 1;
                if (cur_len < ans_len){
                    ans_len = cur_len;
                    start = l;
                }
                s_count[s[l]]--;
                if (t_count.count(s[l]) && s_count[s[l]] < t_count[s[l]]){
                have -= 1;
                }
                l++; 
            }
        }
        if (ans_len == INT_MAX){
            return "";
        }
        return s.substr(start, ans_len);

    }
};