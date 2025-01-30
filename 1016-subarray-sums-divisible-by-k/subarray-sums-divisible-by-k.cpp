class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans=0;
        int temp=0;
        unordered_map<int,int> check;
        check[0]=1;//to ensure that at i =0 if it is subarray then also count then remainder ==0
        for(int i=0;i<nums.size();i++){
            temp+=nums[i];
            int remainder=temp%k;
            if(remainder<0)remainder=remainder+k;//arithmetic not work in negative number so in order to make it k is sum to it
            if(check.find(remainder)!=check.end()){
                ans+=check[remainder];
            }
            check[remainder]++;
        }
        return ans;
    }
};