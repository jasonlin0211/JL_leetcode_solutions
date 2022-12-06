// Written by: Jian-Yuan Lin
// Date: 2022.12.05

class MedianFinder {
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (left.size() == 0 || num <= left.top()){
            left.push(num);
        }
        else{
            right.push(num);
        }
        // maintain the balance of two heaps
        if (left.size() - right.size() == 2){
            int to_pop = left.top();
            left.pop();
            right.push(to_pop);
        }

        if (left.size() < right.size()){
            int to_pop = right.top();
            right.pop();
            left.push(to_pop);
        }
    }
    
    double findMedian() {
        if (left.size() > right.size()){
            return left.top();
        }
        else{
            return (left.top() + right.top()) / 2.0;
        }
    }
private:
    priority_queue<int, vector<int>> left;
    priority_queue<int, vector<int>, greater<int>> right;
    
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */