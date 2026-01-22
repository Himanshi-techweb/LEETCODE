class Solution {
public:
    bool sort_check(vector<int> &nums){
        for(int i=0;i<nums.size()-1;i++){
           if(nums[i]>nums[i+1])return false;
        }
        return true;
    }
    int minimumPairRemoval(vector<int>& nums) {
        int mini=0;
        int count=0;
        vector<int> arr;
        vector<int> check;
        arr=nums;
        if(nums.size()==1)return 0;
        while(!sort_check(arr)){
            int i=0;
            int sum=arr[0]+arr[1];
            for(int k=1;k<arr.size()-1;k++){
              if(arr[k]+arr[k+1]<sum){
                sum=arr[k]+arr[k+1];
                i=k;
              }
            }

            for(int j=0;j<arr.size();j++){
                if(j==i){
                    check.push_back(sum);
                    j++;
                }
                else check.push_back(arr[j]);
            }
            arr=check;
            check.clear();
            count++;
        }
        return count;
    }
};