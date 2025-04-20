class Solution {
public:
    int numRabbits(vector<int>& answers) {
       unordered_map<int, int> count;
        for (int ans : answers) {
            count[ans]++;
        }

        int result = 0;
        for (auto [k, freq] : count) {
            int groupSize = k + 1;
            int groups = (freq + k) / groupSize; // ceil(freq / groupSize)
            result += groups * groupSize;
        }

        return result; 
    }
};