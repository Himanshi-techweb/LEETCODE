class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       //get nextptr which is zero;
       int curr=0;
       while(curr<nums.size()){
        if(nums[curr]==0)break;
        curr++;
       } 
       //start from after it
       int i=curr+1;
       while(i<nums.size()){
        if(nums[i]!=0){
            swap(nums[i],nums[curr]);
            //next curr will that index from curr whose value is zero
            curr++;
        }
        i++;
       }
    }
};