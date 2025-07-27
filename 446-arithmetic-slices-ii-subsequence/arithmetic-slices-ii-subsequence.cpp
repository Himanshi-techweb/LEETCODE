class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        long long n=nums.size();
        long long ans=0;
        vector<unordered_map<long long,long long>> arr(n);
        for(long long i=0;i<n;i++){
            for(long long j=0;j<i;j++){
               long long diff=(long long)nums[i]-nums[j];
               auto x=arr[j].find(diff);
               long long count_j=(x==arr[j].end())?0:x->second;
               arr[i][diff]+=count_j+1;
               ans+=count_j;
            }
        }
        return ans;
    }
};