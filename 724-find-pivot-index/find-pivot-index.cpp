class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int l=0;int n=nums.size();
        vector<int> right(nums.size(),0);
        for(int i=n-2;i>=0;i--){
           right[i]=nums[i+1]+right[i+1];
        }
        
        for(int i=0;i<n;i++){
            if(i==0 && right[i]==0)return 0;
            else if(i!=0){l=nums[i-1]+l;
            if(l==right[i])return i;}

        }
        return -1;

    }
};