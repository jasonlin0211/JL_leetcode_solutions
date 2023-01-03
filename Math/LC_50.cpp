// Written by: Jian-Yuan Lin
// Date: 2023.01.02

class Solution {
public:
    double calculate(double x, long n, unordered_map<long, double>& mem){
        if (mem.count(n)){
            return mem[n];
        }
        if (n == 0){
            mem[0] = 1;
            return 1;
        }
        else if (n < 0){
            mem[n] = 1 / calculate(x, abs(n), mem);
        }
        else if (n % 2 == 0){
            mem[n] = calculate(x, n/2, mem) * calculate(x, n/2, mem);
        }
        else{
            mem[n] = x * calculate(x, n/2, mem) * calculate(x, n/2, mem);
        }
        return mem[n];
    }
    double myPow(double x, int n) {
        // divide and conquer + memoization
        unordered_map<long, double> mem;
        long exp = n;
        return calculate(x, exp, mem);
    }
};