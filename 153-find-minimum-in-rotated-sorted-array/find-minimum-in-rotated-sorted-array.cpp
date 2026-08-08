class Solution {
public:
    int findMin(vector<int>& arr) {
       int l=0;int h=arr.size()-1;
       int ans=INT_MAX;
        while(l<=h){
            int m=(l+h)/2;
            //left sort
            if(arr[l]<=arr[m]){
                ans=min(ans,arr[l]);
                l++;

            }
            //right sort
            else if(arr[m]<=arr[h]){
                ans=min(ans,arr[m]);
                h--;

            }
        } 
        return ans;
    }
};