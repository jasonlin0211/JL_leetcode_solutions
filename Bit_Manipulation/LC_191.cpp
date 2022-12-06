// Written by: Jian-Yuan Lin
// Date: 2022.12.06

class Solution {
public:
    int hammingWeight(uint32_t n) {
        /*
        bit manipulation: use n & (n-1)
        example:
          100001
        & 100000
        ----------
          100000
        & 011111
        ----------
          000000
        use n & (n-1) can eleminate the least significant 1 bit to 0! 
        */

        int ans = 0;
        while (n){
            ans++;
            n = n & (n-1);
        }
        return ans;
    }
};