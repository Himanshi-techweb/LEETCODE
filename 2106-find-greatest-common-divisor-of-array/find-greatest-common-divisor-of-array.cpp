class Solution {
public:
    int findGCD(vector<int>& nums) {
        return gcd((int)*min_element(nums.begin(),nums.end()),*max_element(nums.begin(),nums.end()));
    }
};