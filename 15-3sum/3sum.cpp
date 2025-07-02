class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
    //    vector<vector<int>> ans;
    set<vector<int>> st;
       sort(arr.begin(),arr.end());
       int l=0;int r=arr.size()-1;
       for(int i=0;i<arr.size();i++){
          l=i+1;int sum=arr[i]; r=arr.size()-1;
          while(l<r){
            sum=(arr[l]+arr[r]+arr[i]);
            if(sum==0){
                st.insert({arr[i],arr[l],arr[r]});
                int a=arr[l];int b=arr[r];
                while(l<=r && arr[l]==a)l++;
                while(l<=r && arr[r]==b)r--;
            }
            else if(sum<0)l++;
            else r--;
          }
       }
       vector<vector<int>>ans1; 
       for(auto it:st){
        ans1.push_back(it);
       }
       return ans1;
    }
};