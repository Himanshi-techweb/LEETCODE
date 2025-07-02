class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
       vector<vector<int>> ans;
       sort(arr.begin(),arr.end());
       int l=0;int r=arr.size()-1;
       for(int i=0;i<arr.size();i++){
          if(i-1>=0 && arr[i]==arr[i-1])continue;
          l=i+1;int sum=arr[i]; r=arr.size()-1;
          while(l<r){
            sum=(arr[l]+arr[r]+arr[i]);
            if(sum==0){
                ans.push_back({arr[i],arr[l],arr[r]});
                int a=arr[l];int b=arr[r];l++;r--;
                while(l<r && arr[l]==a)l++;
                while(l<r && arr[r]==b)r--;
            }
            else if(sum<0)l++;
            else r--;
          }
       } 
       return ans;
    }
};