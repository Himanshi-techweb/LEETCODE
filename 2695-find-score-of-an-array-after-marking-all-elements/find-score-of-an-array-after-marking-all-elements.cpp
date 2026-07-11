class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long score=0;
        vector<bool> mark(nums.size(),0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        for(auto i=0;i<nums.size();i++){
            q.push({nums[i],i});
        }
        while(!q.empty()){
            auto frontnum=q.top().first;
            auto fronti=q.top().second;
            q.pop();
            if(!mark[fronti]){
               if(fronti-1>=0)mark[fronti-1]=true;
               if(fronti+1<nums.size())mark[fronti+1]=true; 
               score+=frontnum;
            }
        }
        return score;
    }
};