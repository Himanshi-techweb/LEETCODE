class Solution {
public:
    int f(vector<int> &arr,int k){
        if(k<0)return 0;
        unordered_map<int,int> check;
        int l=0;int r=0;int cnt=0;
        while( r<arr.size()){
            check[arr[r]]++;
            while(check.size()>k){
                check[arr[l]]--;
                if(check[arr[l]]==0)check.erase(arr[l]);
                l++;
            }
            cnt+=(r-l+1);
            r++;
        } 
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& arr, int k) {
       return f(arr,k)-f(arr,k-1);
    }
};