class KthLargest {
public:
    priority_queue<int,vector<int> ,greater<int>>q;
    int n;
    KthLargest(int k, vector<int>& nums) {
        n=nums.size();
        int x=k;int i=0;
        while(x>0 && i<nums.size()){
            q.push(nums[i++]);
            x--;
        }
        while(x>0){
            q.push(INT_MIN);
            x--;
        }
        for(;i<nums.size();i++){
            if(q.top()<nums[i]){
                q.pop();
                q.push(nums[i]);
            }
        }
    }
    
    int add(int val) {
        if(q.empty()){
            q.push(val);
            
        }
        else if(q.top()<val){
            q.pop();
            q.push(val);
        }
        return q.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */