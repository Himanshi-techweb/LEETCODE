class Solution {
public:
    void solve(vector<int>&arr,int st,int end,int &ans){
        if(st>end)return ;
        int mid=(st+end)/2;
        if(arr[st]<=arr[mid]){
            ans=min(ans,arr[st]);
            solve(arr,mid+1,end,ans);
        }
        else{
            ans=min(ans,arr[mid]);
            solve(arr,st,mid-1,ans);
        }
    }
    int findMin(vector<int>& nums) {
       if(nums.size()==1){
        return nums[0];
       } 
       int ans=INT_MAX;
       solve(nums,0,nums.size()-1,ans);
       return ans;
    }
};