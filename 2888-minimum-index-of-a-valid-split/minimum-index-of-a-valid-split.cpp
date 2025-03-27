class Solution {
public:
    int minimumIndex(vector<int>& arr) {
        int n = arr.size();
        map<int, int> freq;

        // Step 1: Find the dominant element
        for (int num : arr) {
            freq[num]++;
        }
        
        int dominant = -1;
        for (auto& [num, count] : freq) {
            if (count * 2 > n) {
                dominant = num;
                break;
            }
        }

        if (dominant == -1) return -1; // No dominant element

        // Step 2: Check for the minimum index where it remains dominant
        int leftCount = 0, totalCount = freq[dominant];

        for (int i = 0; i < n - 1; i++) {
            if (arr[i] == dominant) leftCount++;

            int rightCount = totalCount - leftCount;
            if (leftCount * 2 > (i + 1) && rightCount * 2 > (n - i - 1)) {
                return i;
            }
        }

        return -1; // No valid split found
    }
};