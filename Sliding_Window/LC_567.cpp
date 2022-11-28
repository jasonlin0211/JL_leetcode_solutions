// Written by: Jian-Yuan Lin
// Date: 2022.11.28

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()){
            return false;
        }
        vector<int> s1_count(26, 0), s2_count(26, 0);
        for (char ch: s1){
            s1_count[ch - 'a']++;
        }
        for (int i = 0; i < s2.size(); i++){
            s2_count[s2[i] - 'a']++;
            // if the current substring length is longer than the goal, move left pointer
            if (i >= s1.size()){
                s2_count[s2[i-s1.size()] - 'a']--;
            }
            if (s1_count == s2_count){
                return true;
            }
        }
        return false;
    }
};