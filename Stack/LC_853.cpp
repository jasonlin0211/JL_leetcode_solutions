// Written by: Jian-Yuan Lin
// Date: 2022.12.05

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<double, double>> cars;
        for (int i = 0; i < position.size(); i++){
            cars.push_back({position[i], speed[i]});
        }
        
        sort(cars.begin(), cars.end(), [] (const auto a, const auto b){
            if (a.first == b.first){
                return a.second < b.second;
            }
            return a.first < b.first;
        });
        stack<double> s;
    
        for (int i = cars.size() - 1; i >= 0; i--){
            // be careful here needs to be double!
            double t_need = (target - cars[i].first) / cars[i].second;
            while(!s.empty() && s.top() >= t_need){
                double prev = s.top();
                s.pop();
                t_need = prev;
            }
            s.push(t_need);
        }
        return s.size();
    }
};