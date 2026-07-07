class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
       priority_queue<int,vector<int>,greater<int>>q;
       int i=0;
       
       for(auto it:nums){
        q.push(it);
        while(q.size()>k)q.pop();
       }
       return q.top();
    }
};