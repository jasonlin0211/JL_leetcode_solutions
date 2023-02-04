// Date: 2023.02.02
// Written by Jian-Yuan Lin

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.size()){
            return s;
        }
        vector<string> word(numRows, "");
        int step = 1, idx = 0, i = 0;
        while (i < s.size()){
            word[idx] += s[i];
            idx += step;
            if (idx == 0){
                step = 1;
            }
            else if (idx == numRows - 1){
                step = -1;
            }
            i++;
        }
        string ans = "";
        for (string s: word){
            ans += s;
        }
        return ans;
    }
};