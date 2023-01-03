// Written by: Jian-Yuan Lin
// Date: 2023.01.02

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // very clever way, consider do the calculation
        // from the end
        for (int i = digits.size() - 1; i >= 0; i--){
            // no carry generated
            if (digits[i] < 9){
                digits[i]++;
                return digits;
            }
            // carry generated
            digits[i] = 0;
        }
        // example like 999, we need to set the first as 1 and push a new 0
        digits[0] = 1;
        digits.push_back(0);
        return digits;
    }
    /* brute force is okay in Python, but will cause overflow 
       in C++
    int convert_int(vector<int>& digits){
        int ans = 0;
        for (int d: digits){
            ans = ans * 10 + d;
        }
        ans++;
        return ans;
    }
    vector<int> convert_vec(int n){
        vector<int> ans;
        while(n){
            ans.push_back(n % 10);
            n /= 10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    vector<int> plusOne(vector<int>& digits) {
        int n = convert_int(digits);
        vector<int> ans = convert_vec(n);
        return ans;
    }
    */
};