class Solution {
public:
    bool isTrionic(vector<int>& nums) {
       int p ,q;int i=0;
       bool inc1=false;bool inc2=false;bool dec =false;
       for(;i+1<nums.size();i++){
        if(nums[i]==nums[i+1])return false;
        if(nums[i]<nums[i+1])continue;
        p=i;
        break;
       } 
       if(p!=0)inc1=true;
       for(int i=p;i+1<nums.size();i++){
        if(nums[i]==nums[i+1])return false;
        if(nums[i]>nums[i+1])continue;
        q=i;
        break;
       }
       if(p!=q && q!=nums.size()-1)dec=true;
       for(i=q;i+1<nums.size();i++){
        if(nums[i]==nums[i+1])return false;
        if(nums[i]>nums[i+1]){
            break;
        }
       }
       if(i==nums.size()-1)inc2=true;
       return inc1 && dec && inc2;
    }
};