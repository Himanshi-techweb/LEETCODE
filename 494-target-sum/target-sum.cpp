class Solution {
public:
    int solve(int i,int tar,vector<int> &arr,int total){
        if(i==0){
            if(tar==arr[0] && tar==0)return 2;
            else if(tar==arr[0] || tar==0)return 1;
            return 0;
        }
        int take=0;
        if(arr[i]<=tar)take=solve(i-1,tar-arr[i],arr,total);
        int nottake=solve(i-1,tar,arr,total);
        return take+nottake;
    }
    int findTargetSumWays(vector<int>& arr, int target) {
       int total=accumulate(arr.begin(),arr.end(),0);
       int m=arr.size();
       if((total+target)%2!=0)return 0;
       target=(total+target)/2;
       return solve(m-1,target,arr,total);
    }
};