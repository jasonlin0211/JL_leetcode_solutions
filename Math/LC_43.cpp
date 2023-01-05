// Written by: Jian-Yuan Lin
// Date: 2023.01.04

class Solution {
public:
    string multiply(string num1, string num2) {
        // this is definitely not a easy problem, tricky enough but worth learning
        if (num1 == "0" || num2 == "0"){
            return "0";
        }
        // reverse the two string first since we are going to conduct the multiplication
        // from the end
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        vector<int> result(num1.size() + num2.size(), 0);
        
        for(int i = 0; i < num1.size(); i++){
            for (int j = 0; j < num2.size(); j++){
                int digit = (num1[i] - '0') * int(num2[j] - '0');
                result[i+j] += digit;
                // calculate carry
                result[i+j+1] += (result[i+j]/10);
                result[i+j] = result[i+j]%10;
            }
        }
        reverse(result.begin(), result.end());
        // find nonzero index
        int nonzero_idx = 0;
        while (nonzero_idx < result.size() && result[nonzero_idx] == 0){
            nonzero_idx++;
        }
        string ans = "";
        for (int i = nonzero_idx; i < result.size(); i++){
            ans += to_string(result[i]);
        } 
        return ans;
           
    }
};