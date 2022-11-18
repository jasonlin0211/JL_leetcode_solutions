// Written by: Jian-Yuan Lin
// Date: 2022.11.17

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (int num: nums){
            count[num]++;
        }
        // construct the freq -> num map
        // can be replaced using bucket sort!
        
        int max_freq = 0;
        unordered_map<int, vector<int>> freq_num;
        for (auto it = count.begin(); it != count.end(); it++){
            int num = it->first, freq = it->second;
            freq_num[freq].push_back(num);
            max_freq = max(max_freq, freq);
        }
        vector<int> ans;
        while (k > 0){
            for(int i = 0; i < freq_num[max_freq].size(); i++){
                ans.push_back(freq_num[max_freq][i]);
                k -= 1;
                if (k == 0){
                    return ans;
                }
            }
            max_freq -= 1;
        }
        return ans;
        /* bucket sort version
        unordered_map<int, int> count;
        int maxfreq = 0;
        for (int num: nums){
            count[num]++;
            maxfreq = max(maxfreq, count[num]);
        }
        vector<vector<int>> bucket(maxfreq + 1);
        for (auto it = count.begin(); it != count.end(); it++){
            bucket[it->second].push_back(it->first);
        }
        vector<int> ans;
        for (int i = bucket.size()-1; i >= 0; i--){
            if (ans.size() == k){
                break;
            }
            if (!bucket[i].empty()){
                for (int j = 0; j < bucket[i].size(); j++){
                    ans.push_back(bucket[i][j]);
                }
            }
        }
        return ans;
        */
    }
};