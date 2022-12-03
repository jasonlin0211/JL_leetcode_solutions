// Written by: Jian-Yuan Lin
// Date: 2022.12.02

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> count;
        for (char ch : s){
            count[ch] += 1;
        }
        vector<pair<int, int>> count_list;
        for (auto i = count.begin(); i != count.end(); i++){
            char ch = i->first;
            int freq = i->second;
            
            count_list.push_back({freq, ch});
        }
        sort(count_list.begin(), count_list.end(), [](const auto& a, const auto& b){
            return a.first > b.first;
        });
        string ans = "";
        for(auto i = count_list.begin(); i != count_list.end(); i++){
            char ch = i->second;
            int freq = i->first;
            
            while (freq != 0){
                ans += ch;
                freq--;
            }
        }
        return ans;
    }
};