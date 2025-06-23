class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int m=arr.size();
        vector<int> left(m,0);
        left[m-1]=arr[m-1];
        vector<int> right(m,0);
        right[0]=arr[0];
        for(int i=m-2;i>=0;i--){
           left[i]=max(left[i+1],arr[i]);
        }
        for(int i=1;i<m;i++){
            right[i]=min(right[i-1],arr[i]);
        }
        int maxi=0;
        for(auto int i=0;i<m;i++){
            maxi=max(maxi,left[i]-right[i]);
        }
        return maxi;
    }
};