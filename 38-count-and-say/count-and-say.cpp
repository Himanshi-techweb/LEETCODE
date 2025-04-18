class Solution {
public:
    string countAndSay(int n) {
       string result = "1";
        for (int i = 2; i <= n; ++i) {
            string curr = "";
            int count = 1;
            for (int j = 1; j < result.size(); ++j) {
                if (result[j] == result[j - 1]) {
                    count++;
                } else {
                    curr += to_string(count) + result[j - 1];
                    count = 1;
                }
            }
            // Add the last group
            curr += to_string(count) + result.back();
            result = curr;
        }
        return result; 
    }
};