class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       int cnt=0;
       unordered_map<int,int> q;
       int sum=0;
       q[0]=1;
       for(int i=0;i<nums.size();i++){
        
        sum+=nums[i];
        
        if(q.find(sum-k)!=q.end()){
            cnt+=q[sum-k];
        }
        q[sum]++;
       } 
       return cnt;
    }
};