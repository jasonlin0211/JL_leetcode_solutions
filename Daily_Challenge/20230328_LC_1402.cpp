class Solution {
public:
    int dp(int i, int t, unordered_map<int, unordered_map<int, int>>& mem, vector<int>& satisfaction){
         if (i >= satisfaction.size()){
             return 0;
         }
         if (mem.count(i) && mem[i].count(t)){
             return mem[i][t];
         }
         mem[i][t] = 0;
         // choose to cook
         mem[i][t] = max(mem[i][t], t * satisfaction[i] + dp(i+1, t+1, mem, satisfaction));
         // choose to not cook
         mem[i][t] = max(mem[i][t], dp(i+1, t, mem, satisfaction));
         return mem[i][t];
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        unordered_map<int, unordered_map<int, int>> mem;

        return dp(0, 1, mem, satisfaction);
    }
};