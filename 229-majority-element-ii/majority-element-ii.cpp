class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1=-1;
        int num2=-1;
        int cnt1=0;
        int cnt2=0;
        for(int i=0;i<nums.size();i++){
            if(num1==-1 && num2!=nums[i]){
                num1=nums[i];
                cnt1=1;
            }
            else if(nums[i]==num1)cnt1++;
            else if(num2==-1 && num1!=nums[i]){
                num2=nums[i];
                cnt2=1;
            }
            else if(nums[i]==num2)cnt2++;
            else{
                cnt1--;
                if(cnt1==0)num1=-1;
                cnt2--;
                if(cnt2==0)num2=-1;
            }
        }
        int cnt=0;
        cnt=1+(nums.size()/3);
        cnt1=0;cnt2=0;
        for(int i=0;i<nums.size();i++){
           if(nums[i]==num1)cnt1++;
           if(nums[i]==num2)cnt2++;
        }
        vector<int> ans;
        if(cnt1>=cnt)ans.push_back(num1);
        if(cnt2>=cnt && num2!=num1)ans.push_back(num2);
        return ans;
    }
};