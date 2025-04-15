class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;int n=arr.size();
        for(int i=0;i<arr.size();i++){
            if(i>0 && arr[i]==arr[i-1])continue;
            int j=i+1;int k=n-1;
            while(j<k){
                int sum=arr[i]+arr[j]+arr[k];
                if(sum<0)j++;
                else if(sum>0)k--;
                else{
                    vector<int> check;
                    check.push_back(arr[i]);
                    check.push_back(arr[j]);
                    check.push_back(arr[k]);
                    ans.push_back(check);
                    j++;k--;
                    while(j<k && arr[j]==arr[j-1])j++;
                    while(j<k && arr[k]==arr[k+1])k--;
                }
            }
        }return ans;
    }
};