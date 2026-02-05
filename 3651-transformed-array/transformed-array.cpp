class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> result(n,0);
        for(int i=0;i<n;i++){
            int newindex=(i+nums[i])%n;
            if(newindex<0)newindex=newindex+n;
            result[i]=nums[newindex];
        }
        return result;
    }
};

