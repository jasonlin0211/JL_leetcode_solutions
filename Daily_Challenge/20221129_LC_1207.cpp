// Written by: Jian-Yuan Lin
// Date: 2022.11.29

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> count;
        for (int num: arr){
            count[num] += 1;
        }
        unordered_set<int> seen;
        for (auto i = count.begin(); i != count.end(); i++){
            int freq = i->second;
            if (seen.count(freq)){
                return false;
            }
            seen.insert(freq);
        }
        return true;
    }
};