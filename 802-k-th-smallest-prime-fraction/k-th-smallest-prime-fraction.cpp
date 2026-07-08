class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<double,pair<int,int>>> q;
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                double fract=(double)arr[i]/arr[j];
                q.push({fract,{arr[i],arr[j]}});
                while(q.size()>k){
                   q.pop();
                }
            }
        }
        // cout<<q.size()<<endl;
        
        auto front=q.top();
        vector<int> ans;
        ans.push_back(front.second.first);
        ans.push_back(front.second.second);
        
        return ans;
    }
};