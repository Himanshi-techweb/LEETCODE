class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sumNums1 = 0; // Sum of elements in nums1
        long long sumNums2 = 0; // Sum of elements in nums2
        bool hasZero = false;   // Flag to check if nums1 contains a zero

        // Calculate the sum for nums1, replacing zeros with ones
        for (int num : nums1) {
            if (num == 0) hasZero = true;
            sumNums1 += std::max(num, 1);
        }

        // Calculate the sum for nums2, replacing zeros with ones
        for (int num : nums2) {
            sumNums2 += std::max(num, 1);
        }

        // If sum of nums1 is greater than sum of nums2, reverse the order and call minSum again
        if (sumNums1 > sumNums2) {
            return minSum(nums2, nums1);
        }

        // If sums are equal, return the sum
        if (sumNums1 == sumNums2) {
            return sumNums1;
        }

        // If there's a zero in nums1 and sums are unequal, it's possible to equalize
        // Otherwise, it's impossible
        return hasZero ? sumNums2 : -1;
    }
};