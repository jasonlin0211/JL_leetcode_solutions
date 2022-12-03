// Written by: Jian-Yuan Lin
// Date: 2022.12.02

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()){
            return false;
        }
        unordered_map<char, int> count1, count2;
        for (int i = 0; i < word1.size(); i++){
            count1[word1[i]]++;
            count2[word2[i]]++;
        }
        vector<char> char_word1, char_word2;
        vector<int> freq_word1, freq_word2;
        for (auto item: count1){
            char_word1.push_back(item.first);
            freq_word1.push_back(item.second);
        }
        for (auto item: count2){
            char_word2.push_back(item.first);
            freq_word2.push_back(item.second);
        }
        sort(char_word1.begin(), char_word1.end());
        sort(char_word2.begin(), char_word2.end());
        if (char_word1 != char_word2){
            return false;
        }
        sort(freq_word1.begin(), freq_word1.end());
        sort(freq_word2.begin(), freq_word2.end());
        return freq_word1 == freq_word2;
    }
};