class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        unordered_map<int,unordered_map<int,long long>> st;
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<i;j++){
                long long diff=(long long)nums[j]-nums[i];
                auto it=st[j].find(diff);
                int count_j=(it==end(st[j]))?1:it->second;
                st[i][diff]=max(1+count_j,(int)st[i][diff]);
                ans=max(ans,st[i][diff]);
            }
        }
        return ans;

        //for each index check
    }
};