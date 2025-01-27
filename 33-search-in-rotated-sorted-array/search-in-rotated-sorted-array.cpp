class Solution {
public:
    void solve(int st,int end,int target ,vector<int> &arr,int &ans){
        if(st==end)return;
        int pivot=(st+end)/2;
        if(arr[pivot]==target)ans=pivot;    
        solve(st,pivot,target,arr,ans);
        solve(pivot+1,end,target,arr,ans);
    }
    int search(vector<int>& nums, int target) {
        if(nums.size()==1 && nums[0]==target)return 0;
       int st=0;
       int end=nums.size();
       int ans=-1;
       solve(st,end,target,nums,ans);
       return ans;
    }
};