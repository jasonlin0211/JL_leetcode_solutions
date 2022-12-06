// Written by: Jian-Yuan Lin
// Date: 2022.12.05

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        //basic max heap based solution
        vector<vector<int>> ans;
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>> pq;
        for (int i = 0; i < points.size(); i++){
            int x = points[i][0], y = points[i][1];
            pq.push({x * x + y * y, {x, y}});
            if (pq.size() > k){
                pq.pop();
            }
        }
        while(!pq.empty()){
            auto item = pq.top();
            pq.pop();
            ans.push_back(item.second);
        }
        return ans;
        
    }
};