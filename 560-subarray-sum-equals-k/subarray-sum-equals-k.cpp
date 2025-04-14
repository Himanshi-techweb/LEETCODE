class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
       //vector<int> check(nums.size());
       int ans=0;
       unordered_map<int,int> check;int sum=0;
       for(auto x:arr){
         sum+=x;
         if(sum==k)ans++;
         if(check.find(sum-k)!=check.end()){
            ans+=check[sum-k];
         }
         check[sum]++;
       }
       return ans;
    }
};