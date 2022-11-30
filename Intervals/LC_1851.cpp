// Written by: Jian-Yuan Lin
// Date: 2022.11.30

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        unordered_map<int, int> result;
        vector<int> ans;
        vector<int> sorted_queries = queries;
        sort(sorted_queries.begin(), sorted_queries.end());
        sort(intervals.begin(), intervals.end());
        // important to learn how to use priority queue to store pair
        // store (length of interval, end of interval)
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        int i = 0;
        for (int j = 0; j < sorted_queries.size(); j++){
            int q = sorted_queries[j];
            // put all of the possible intervals in the pq
            while (i < intervals.size() && intervals[i][0] <= q){
                int l = intervals[i][0], r = intervals[i][1];
                pq.push({r-l+1, r});
                i++;
            }
            // pop those don't contain q
            while(!pq.empty() && pq.top().second < q){
                pq.pop();
            }
            if (!pq.empty()){
                result[q] = pq.top().first;
            }
            else{
                result[q] = -1;
            }
        }

        for (int q: queries){
            ans.push_back(result[q]);
        }
        return ans;
    }
};