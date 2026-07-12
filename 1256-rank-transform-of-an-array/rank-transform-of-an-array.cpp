class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        for(auto i=0;i<arr.size();i++){
            q.push({arr[i],i});
        }
        vector<int> ans(arr.size(),0);
        int cnt=1;
        int prev=INT_MIN;
        while(!q.empty()){
            auto front=q.top();
            q.pop();
            int i=front.second;
            int num=front.first;
            
            ans[i]=cnt;
            if(!q.empty() && q.top().first!=num)cnt++;
            
        }
        return ans;
    }
};