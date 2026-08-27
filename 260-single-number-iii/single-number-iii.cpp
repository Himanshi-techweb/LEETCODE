class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        long long xorr=0;
        for(auto it:nums)xorr=xorr^it;
        long long rightmost=xorr & -xorr;
        int b1=0;int b2=0;
        for(auto it:nums){
            if((it&rightmost)==0)b1=b1^it;
            else b2=b2^it;
        }
        return {b1,b2};
    }
};