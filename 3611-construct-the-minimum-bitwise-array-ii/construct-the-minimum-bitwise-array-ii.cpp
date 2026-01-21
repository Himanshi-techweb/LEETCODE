class Solution {
public:
    string toBinary(int n) {
    string s = "";
    while (n > 0) {
        s = char('0' + (n % 2)) + s;
        n /= 2;
    }
    return s;
    }
    int toDecimal(string s) {
    int val = 0;
    for (char c : s) {
        val = val * 2 + (c - '0');
    }
    return val;
    }
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans(nums.size(),-1);
        for(int i=0;i<nums.size();i++){
            if(nums[i]==2)continue;
            int x=nums[i];
            bool flag=false;
            for(int j=0;j<32;j++){
                if((nums[i] & (1<<j)) >0)continue;
                else{
                    int prev=j-1;
                    x=nums[i] ^ (1<<prev);
                    flag=true;
                }
                if(flag){
                  ans[i]=x;
                  break;
                }  
           } 
        }
        return ans;
    }
};