// Written by: Jian-Yuan Lin
// Date: 2023.01.13

class Solution {
public:
    int find(int x, vector<int>& root){
        if (x != root[x]){
            root[x] = find(root[x], root);
        }
        return root[x];
    }

    void do_union(int x, int y, vector<int>& root){
        int rx = find(x, root), ry = find(y, root);
        if (rx != ry){
            if (rx < ry){
                root[ry] = rx;
            }
            else{
                root[rx] = ry;
            }
        }
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int> root(26, 0);
        for (int i = 0; i < 26; i++){
            root[i] = i;
        }
        for (int i = 0; i < s1.size(); i++){
            char c1 = s1[i], c2 = s2[i];
            do_union(int(c1) - int('a'), int(c2) - int('a'), root);
        }
        string chars = "abcdefghijklmnopqrstuvwxyz";
        string ans = "";
        for (int i = 0; i < baseStr.size(); i++){
            ans += chars[find(int(baseStr[i]) - int('a'), root)];
        }
        return ans;
    }
};