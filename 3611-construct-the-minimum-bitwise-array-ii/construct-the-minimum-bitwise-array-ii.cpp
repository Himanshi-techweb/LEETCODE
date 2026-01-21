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
           string x=toBinary(nums[i]);
           int size=x.size();
           size--;
           while(size>=0 && x[size]=='1')size--;
            
            size++;
            x[size]='0';
           ans[i]=toDecimal(x);
        }
        return ans;
    }
};