class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int n=arr.size();
        long long sum1=n*(n+1)/2;
        long long sum2=accumulate(arr.begin(),arr.end(),0);
        return sum1-sum2; 
    }
};