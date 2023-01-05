// Written by: Jian-Yuan Lin
// Date: 2023.01.04

class DetectSquares {
public:
    DetectSquares() {
        
    }
    // too lazy to rewrite the entire code, will do it maybe tomorrow...
    void add(vector<int> point) {
        points[point[0]][point[1]]++;
    }
    
    int count(vector<int> point) {
        int x1 = point[0];
        int y1 = point[1];
        
        int result = 0;
        
        for (auto x = points.begin(); x != points.end(); x++) {
            unordered_map<int, int> yPoints = x->second;
            for (auto y = yPoints.begin(); y != yPoints.end(); y++) {
                int x3 = x->first;
                int y3 = y->first;
                
                // skip points on same x-axis or y-axis
                if (abs(x3 - x1) == 0 || abs(x3 - x1) != abs(y3 - y1)) {
                    continue;
                }
                
                result += points[x3][y3] * points[x1][y3] * points[x3][y1];
            }
        }
        
        return result;
    }
private:
    // {x -> {y -> count}}
    // NOTE we can't use tuple or pair as a key in the unordered_map
    // in C++, since there's no built-in hash function 
    unordered_map<int, unordered_map<int, int>> points;
};