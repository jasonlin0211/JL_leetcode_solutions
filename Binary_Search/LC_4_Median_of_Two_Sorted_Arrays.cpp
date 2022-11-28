// Written by: Jian-Yuan Lin
// Date: 2022.11.22

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if (m > n){
            return findMedianSortedArrays(nums2, nums1);
        }
        // edge case if nums1 is empty
        if (m == 0){
            if (n % 2 == 1){
                return nums2[n/2];
            }
            else{
                return (nums2[n/2 - 1] + nums2[n/2]) / 2.0;
            }
        }
        // the idea is to binary search on the smaller nums, get m1 numbers (A[0] ~ A[m1-1]) and get m2 numbers (B[0] ~ B[m2-1])
        // m1 + m2 = k = (m + n + 1)/ 2
        // compare condition: A[m1] < B[m2-1] -> move right since A[m1] is not big enough to cover B[m2-1]
        // once we reach that, the median must came from A_m1-1, A_m1, B_m2-1, B_m2
        // we can use C1 = max(A_m1-1, B_m2-1), C2 = min(A_m1, B_m2)
        int k = (m + n + 1) / 2;
        int l = 0, r = m;

        while (l < r){
            int m1 = l + (r-l)/2;
            int m2 = k - m1;
            if (nums1[m1] < nums2[m2-1]){
                l = m1 + 1;
            }
            else{
                r = m1;
            }
        }
        int m1 = l, m2 = k - l;

        // be careful here
        // c1 can be found by C1 = max(A_m1-1, B_m2-1), but it's possible that m1 <= 0 or m2 <= 0 --> didn't use any of them
        int c1 = max(m1 <= 0 ? INT_MIN : nums1[m1-1], m2 <= 0 ? INT_MIN : nums2[m2-1]);
        if ((m+n) % 2 == 1){
            return c1;
        }
        // calculate c2 = min(A_m1, B_m2), but same consideration, if m1 >= m means out of bound
        int c2 = min(m1 >= m ? INT_MAX : nums1[m1], m2 >= n ? INT_MAX: nums2[m2]);
        return (c1 + c2) / 2.0;

        /*
        // binary search method is very tricky, try brute force first
        // improve brute force by using two pointers
        int p1 = 0, p2 = 0;
        vector<int> result;
        while (p1 < nums1.size() && p2 < nums2.size()){
            if (nums1[p1] < nums2[p2]){
                result.push_back(nums1[p1]);
                p1++;
            }
            else{
                result.push_back(nums2[p2]);
                p2++;
            }
        }
        while (p1 < nums1.size()){
            result.push_back(nums1[p1]);
            p1++;
        }
        while (p2 < nums2.size()){
            result.push_back(nums2[p2]);
            p2++;
        }
        int n = result.size();
        double ans;
        if (n % 2 == 1){
            ans = result[n/2];
        }
        else{ 
            ans = (result[n/2 - 1] + result[n/2]) / 2.0;
        }
        return ans;*/
    }
};