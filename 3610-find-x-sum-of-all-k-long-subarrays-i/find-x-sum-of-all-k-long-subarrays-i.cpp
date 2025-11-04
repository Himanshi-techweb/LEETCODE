class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int z) {
        int i=0;int j=0;
        vector<int> answer;
       while(true){
         j=i+k-1;
         if(j>=nums.size())break;
         vector<int> curr(51,0);
         for(int x=i;x<=j;x++){
            curr[nums[x]]++;
         }
         map<int, set<int, greater<int>>, greater<int>> m;
         for(int x=0;x<curr.size();x++){
            if(curr[x]==0)continue;
            m[curr[x]].insert(x);
         }
         int cnt=0;int ans=0;
         for(auto it1:m){
          for(auto it2:it1.second){
            cnt++;
            ans+=(it1.first*it2);
            if(cnt==z)break;
          }
          if(cnt==z)break;
         }
         answer.push_back(ans);
         i++;
       }
       return answer;
    }
};