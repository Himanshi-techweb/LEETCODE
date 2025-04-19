class Solution {
public:
    long long countFairPairs(vector<int>& arr, int lower, int upper) {
        long long count=0;
       sort(arr.begin(),arr.end());
       for(int i=0;i<arr.size();i++){
         auto lower_freq=lower_bound(arr.begin()+i+1,arr.end(),lower-arr[i]);
         auto upper_freq=upper_bound(arr.begin()+i+1,arr.end(),upper-arr[i]);
         count+=(upper_freq-lower_freq);
       } return count;
    }
};