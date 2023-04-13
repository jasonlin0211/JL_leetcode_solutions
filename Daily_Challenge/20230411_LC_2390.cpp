class Solution {
public:
    string removeStars(string s) {
        vector<char> stk;
        for(char c: s){
            if (c != '*'){
                stk.push_back(c);
            }
            else{
                stk.pop_back();
            }
        }
        string ans = "";
        for (char c: stk){
            ans += c;
        }
        return ans;
    }
};