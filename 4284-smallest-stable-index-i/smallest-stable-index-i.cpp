class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> mini(n,0);
        vector<int> maxi(n,0);
        maxi[0]=nums[0];mini[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            maxi[i]=max(nums[i],maxi[i-1]);
            mini[n-i-1]=min(nums[n-i-1],mini[n-i]);
        }
        
        for(int i=0;i<n;i++){
            if(maxi[i]-mini[i]<=k)return i;
        }
        for(int i=0;i<n;i++){
            cout<<maxi[i] <<" "<<mini[i]<<endl;
        }
        return -1;
    }
};