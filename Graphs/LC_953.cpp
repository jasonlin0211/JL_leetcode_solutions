class Solution {
public:
    bool check_unsorted(string& first, string& second, unordered_map<char, int>& pos){
        for (int i = 0; i < first.size(); i++){
            if (i == second.size()){
                return true;
            }
            if (first[i] != second[i]){
                if (pos[first[i]] > pos[second[i]]){
                    return true;
                }
                return false;
            }
        }
        return false;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> pos;
        for (int i = 0; i < order.size(); i++){
            pos[order[i]] = i;
        }
        for (int i = 0; i < words.size() - 1; i++){
            string first = words[i], second = words[i+1];
            if (check_unsorted(first, second, pos)){
                return false;
            }
            
        }
        return true;
    }
};