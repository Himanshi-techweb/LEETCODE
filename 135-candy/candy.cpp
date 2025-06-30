class Solution {
public:
    int candy(vector<int>& arr) {
       vector<int> ans(arr.size(),1);
       for(int i=1;i<arr.size();i++){
        if(arr[i]>arr[i-1]){
            ans[i]+=(ans[i-1]);
        }
       }
       for(int i=arr.size()-2;i>=0;i--){
        if(arr[i]>arr[i+1]){
            ans[i]=max(ans[i],(1+ans[i+1]));
        }
       }
       
       return accumulate(ans.begin(),ans.end(),0);
    }
};