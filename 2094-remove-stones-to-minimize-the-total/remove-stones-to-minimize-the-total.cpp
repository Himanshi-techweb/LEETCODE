class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> q;
        for(auto it:piles){
            q.push(it);
        }
        for(int i=0;i<k;i++){
            auto front=q.top();
            q.pop();
            cout<<front<<" ";
            
            if(front%2==0)
            q.push(front/2);
            else q.push((front/2)+1);
        }
        int ans=0;
        while(!q.empty()){
            auto front=q.top();
            q.pop();
            ans+=front;
        }
        return ans;
    }
};