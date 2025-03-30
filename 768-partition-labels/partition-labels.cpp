class Solution {
public:
    // vector<int> partitionLabels(string s) {
        
    // }
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> lastIndex;
        vector<int> result;

        // Step 1: Find the last occurrence of each character
        for (int i = 0; i < s.size(); i++) {
            lastIndex[s[i]] = i;
        }

        // Step 2: Partition the string
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); i++) {
            end = max(end, lastIndex[s[i]]);
            
            // If we reach the end of the partition
            if (i == end) {
                result.push_back(end - start + 1);
                start = i + 1;
            }
        }

        return result;
    }
};