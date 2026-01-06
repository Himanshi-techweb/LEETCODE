class Solution {
public:
    void nextPermutation(vector<int>& nums) {
       //find first index at which it is increasing
       int i=nums.size()-2;
       int ix=-1;
       while(i>=0){
        if(nums[i]<nums[i+1]){
          ix=i;
          break; 
        }
        i--;
       } 
       if(ix==-1){
        reverse(nums.begin(),nums.end());
        return;
       }
       //next largest number to it 
       int before=INT_MAX;int k=-1;
       for(int j=ix+1;j<nums.size();j++){
        if(nums[ix]<nums[j] && before>nums[j]){
          k=j;
          before=nums[j];
        }
       }
       if(k!=-1)swap(nums[ix],nums[k]);
       sort(nums.begin()+ix+1,nums.end());
    }
};