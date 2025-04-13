class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int sum=0;int ans=INT_MIN;
        //if(arr.size()==1)return arr[0];
     for(auto x:arr){
        sum+=x;
        ans=max(ans,sum);
        if(sum<0)sum=0;
     }  return ans; 
    }
};