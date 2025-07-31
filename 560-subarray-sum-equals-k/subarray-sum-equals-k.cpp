class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
       unordered_map<int,int> check;
       int sum=0;int cnt=0;
       for(int i=0;i<arr.size();i++){
         sum+=arr[i];
         if(sum==k)cnt++;
         if(check.find(sum-k)!=check.end()){
            cnt+=check[sum-k];
         }
         check[sum]++;
       }
       return cnt; 
    }
};