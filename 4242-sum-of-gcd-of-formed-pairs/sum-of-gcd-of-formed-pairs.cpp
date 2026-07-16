class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<long long> arr(n,0);
        int maxi=nums[0];
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            arr[i]=gcd(maxi,nums[i]);
        }
        sort(arr.begin(),arr.end());
        int l=0;int r=n-1;long long sum=0;
        while(l<r){
            sum+=(gcd(arr[l],arr[r]));
            l++;r--;

        }
        return sum;

        

        
    }
};