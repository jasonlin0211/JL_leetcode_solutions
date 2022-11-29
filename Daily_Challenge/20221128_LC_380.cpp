// Written by: Jian-Yuan Lin
// Date: 2022.11.28


class RandomizedSet {
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (nums_map.count(val)){
            return false;
        }
        nums_map[val] = nums_list.size();
        nums_list.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if (!nums_map.count(val)){
            return false;
        }
        // swap the to be removed element with the last element, then pop the last element
        int idx = nums_map[val];
        nums_map[nums_list.back()] = idx;
        nums_map.erase(val);
        swap(nums_list[idx], nums_list.back());
        nums_list.pop_back();
        return true;
    }
    
    int getRandom() {
        int idx = rand() % nums_list.size();
        return nums_list[idx];
    }
private:
    unordered_map<int, int> nums_map;
    vector<int> nums_list;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */