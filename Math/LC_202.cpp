// Written by: Jian-Yuan Lin
// Date: 2023.01.02

class Solution {
public:
    int find_next(int n){
        int temp = 0;
        while (n){
            int rem = n % 10;
            temp += rem * rem;
            n /= 10;
        }
        return temp;
    }
    bool isHappy(int n) {
        // try the floyd find cycle algorithm
        int slow = n, fast = find_next(n);

        while (fast != 1 && fast != slow){
            slow = find_next(slow);
            fast = find_next(find_next(fast));
        }
        return fast == 1;

        /*
        // this is essentially the linked list problem
        unordered_map<int, int> mem;
        while (true){
            if (mem.count(n)){
                return mem[n] == 1;
            }
            int temp = find_next(n);
            mem[n] = temp;
            n = temp;
        }
        return false;*/
    }
};