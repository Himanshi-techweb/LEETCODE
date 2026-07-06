class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>q;
        int l=0;int r=costs.size()-1;
        while(l<candidates && l<costs.size()){
            q.push({costs[l],l,-1});//-1 as l 
            l++;
        }
        int cnt=0;
        while(cnt<candidates && r>=l){
            q.push({costs[r],r,-2});//-2 as r
            r--;
            cnt++;
        }
        int cnt1=0;long long ans=0;
        while(!q.empty() && cnt1<k){
            auto front=q.top();
            q.pop();
            int dir=front[2];
            ans+=(long long)front[0];
            if(dir==-1){//left
                if(l<=r){
                    q.push({costs[l],l,-1});
                    l++;
                }
            }
            else if(dir==-2){
                if(r>=l && r>=0){
                    q.push({costs[r],r,-2});
                    r--;
                }
            }
            cnt1++;
        }
        return ans;
    }
};