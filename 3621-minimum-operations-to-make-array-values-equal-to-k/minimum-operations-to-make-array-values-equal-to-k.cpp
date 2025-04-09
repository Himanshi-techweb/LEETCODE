class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
      for (int num : nums) {
        if (num < k)
            return -1;
    }

    // Use a set to store unique values greater than k
    unordered_set<int> greaterThanK;
    for (int num : nums) {
        if (num > k)
            greaterThanK.insert(num);
    }

    // The number of operations is equal to the number of unique elements > k
    return greaterThanK.size();  
    }
};