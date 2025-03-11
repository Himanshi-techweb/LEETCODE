class Solution {
public:
    // int solve(int i,vector<int>&arr,int k){
    //     if(i>=arr.size())return 0;
    //     if()
    // }
    int subarraySum(vector<int>& nums, int k) {
       //vector<int> check(nums.size());
       unordered_map<int,int> check;
       check[0]=1;
       int j=0;
       int sum=0;
       int ans=0;
       while( j<nums.size()){
         sum+=nums[j];
         if(check.find(sum-k)!=check.end()){
            ans+=check[sum-k];
         }
         check[sum]++;
         j++;
       } return ans;
    }
};