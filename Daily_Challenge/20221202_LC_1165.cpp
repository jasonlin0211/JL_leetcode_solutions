// Written by: Jian-Yuan Lin
// Date: 2022.12.02

class Solution {
public:
    int calculateTime(string keyboard, string word) {
        unordered_map<char, int> pos;
        for (int i = 0; i < keyboard.size(); i++){
            pos[keyboard[i]] = i;
        }
        int ans = 0, prev = 0;
        for (char ch: word){
            ans += abs(pos[ch] - prev);
            prev = pos[ch];
        }
        return ans;
    }
};