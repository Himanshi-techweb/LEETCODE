class Solution {
public:
    string check(string &s0){
        //inverse 
        string s="";
        for(int i=s0.size()-1;i>=0;i--){
            s=s+(s0[i]==1?'0':'1');
        }
        return s;
    }
    char findKthBit(int n, int k) {
    if (n == 1) return '0'; // Base case
    int mid = (1 << (n - 1)); // Find the middle position
    
    if (k == mid) return '1'; // Middle bit is always '1'
    if (k < mid) return findKthBit(n - 1, k); // Search in left half
    
    // In the right half, it's the reverse and inverted bit of the left half
    return findKthBit(n - 1, mid * 2 - k) == '0' ? '1' : '0';
    }
};