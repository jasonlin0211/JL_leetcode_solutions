// Written by: Jian-Yuan Lin
// Date: 2022.11.22

class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mapping[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (!mapping.count(key)){
            return "";
        }
        int idx = find_idx(mapping[key], timestamp);
        if (idx == -1){
            return "";
        }
        return mapping[key][idx].second;
    }
private:
    unordered_map<string, vector<pair<int, string>>> mapping;
    // upper bound function
    int find_idx(vector<pair<int, string>>& nums, int val){
        int l = 0, r = nums.size();
        while (l < r){
            int mid = l + (r-l)/2;
            int t = nums[mid].first;
            if (t > val){
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }
        return l - 1;
    }
};
