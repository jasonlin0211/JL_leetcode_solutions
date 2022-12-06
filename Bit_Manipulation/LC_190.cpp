// Written by: Jian-Yuan Lin
// Date: 2022.12.06

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for (int i = 0; i < 32; i++){
            int bit = (n >> i) & 1; // get the ith bit 
            ans = ans | (bit << (31 - i)); // original bit at i will be at 31 - i
        }
        return ans;
    }
};