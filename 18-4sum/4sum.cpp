class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int target) {
       vector<vector<int>> ans;
       sort(arr.begin(),arr.end());
       int l=0;int r=arr.size()-1;
       for(int i=0;i<arr.size();i++){
         if(i-1>=0 && arr[i]==arr[i-1])continue;
         for(int j=i+1;j<arr.size();j++){
            if(j-1>i && arr[j]==arr[j-1])continue;
        //   if(i-1>=0 && arr[i]==arr[i-1])continue;
          l=j+1; r=arr.size()-1;
          while(l<r){
            long long sum=(long long)arr[l]+arr[r]+arr[j]+arr[i];
            if(sum==target){
                ans.push_back({arr[i],arr[j],arr[l],arr[r]});
                int a=arr[l];int b=arr[r];l++;r--;
                while(l<r && arr[l]==a)l++;
                while(l<r && arr[r]==b)r--;
            }
            else if(sum<target)l++;
            else r--;
         }
         }
       } 
       return ans;
    }
};