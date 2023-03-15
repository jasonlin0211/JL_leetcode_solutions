class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0, ans = 0;
        while (i < chars.size()){
            char cur = chars[i];
            int j = i + 1;
            while (j < chars.size() && chars[j] == cur){
                j++;
            }
            int l = j - i;
            if (l == 1){
                chars[ans] = cur;
                i = j;
                ans++;
            }
            else{
                chars[ans] = cur;
                ans++;
                string lens = to_string(l);
                for (int k = 0; k < lens.size(); k++){
                    chars[ans] = lens[k];
                    ans++;
                }
                i = j;
            }
        }

        return ans;
    }
};