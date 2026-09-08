class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1)return 0;
        int cnt=0;int maxloc=0;int currend=0;
        for(int i=0;i<nums.size()-1;i++){
           maxloc=max(maxloc,i+nums[i]);
           if(i==currend){
            cnt++;
            currend=maxloc;
           }  
        }
        return cnt;
    }
};