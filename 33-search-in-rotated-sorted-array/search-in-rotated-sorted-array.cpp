class Solution {
public:
    void solve(int st,int end,int target ,vector<int> &arr,int &ans){
        if(st>end)return ;
        int pivot=(st+end)/2;
        if(arr[pivot]==target){
           ans=pivot; return;
        } 
        if(arr[st]<=arr[pivot] ){
            if(arr[st]<=target && target<arr[pivot]){
                solve(st,pivot-1,target,arr,ans);
            }else{
                solve(pivot+1,end,target,arr,ans);
            }
        }
        else{
            if(arr[pivot]<target && target <=arr[end]){
                solve(pivot+1,end,target,arr,ans);
            }
            else{
                solve(st,pivot-1,target,arr,ans);
            }
        }
    }
    int search(vector<int>& nums, int target) {
        if(nums.size()==1 && nums[0]==target)return 0;
       int st=0;
       int end=nums.size()-1;
       int ans=-1;
       solve(st,end,target,nums,ans);
       return ans;
    }
};