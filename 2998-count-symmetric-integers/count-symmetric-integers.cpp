class Solution {
public:
    // int countSymmetricIntegers(int low, int high) {
        
    // }
    int sumOfDigits(const string& s, int start, int end) {
    int sum = 0;
    for (int i = start; i < end; ++i) {
        sum += s[i] - '0';
    }
    return sum;
}

int countSymmetricIntegers(int low, int high) {
    int count = 0;

    for (int x = low; x <= high; ++x) {
        string s = to_string(x);
        int len = s.length();

        if (len % 2 == 0) {
            int n = len / 2;
            int firstHalfSum = sumOfDigits(s, 0, n);
            int secondHalfSum = sumOfDigits(s, n, len);
            if (firstHalfSum == secondHalfSum) {
                ++count;
            }
        }
    }

    return count;
}

};