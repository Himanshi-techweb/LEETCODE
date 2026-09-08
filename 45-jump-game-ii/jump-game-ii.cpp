class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1)return 0;
        int cnt=0;int l=0;int r=0;int maxi=0;
        while(r<nums.size()-1){
            for(int i=l;i<=r;i++){
                maxi=max(maxi,i +nums[i]);
            }
            l=r+1;
            r=maxi;
            cnt++;
        }
        
        return cnt;
    }
};