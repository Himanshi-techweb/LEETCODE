class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n=obstacles.size();
        vector<int> ans(n);
        vector<int> lis;
        for(int i=0;i<n;i++){
           int x=obstacles[i];
           int lb=upper_bound(lis.begin(),lis.end(),x)-lis.begin();
           if(lis.size()==lb)lis.push_back(x);
           else{
            lis[lb]=x;
           } 
           ans[i]=lb+1;
        }

        return ans;
    }
};