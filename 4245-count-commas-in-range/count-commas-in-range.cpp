class Solution {
public:
    int countCommas(int n) {
        if(n<1000)return 0;
        else if(n==1e5)return 1+ (99999-999);
        else return (n-999);
    }
};