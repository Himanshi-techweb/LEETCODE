class Solution {
public:
    int check(vector<int> & arr,int k,int midvalue){
        int count=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]<=midvalue){
                count++;i++;
            }
            if(count>=k)return true;
        }return false;
    }
    int minCapability(vector<int>& nums, int k) {
        //vector<int> dp(nums.size(),-1);
        int min=*min_element(nums.begin(),nums.end());
        int max=*max_element(nums.begin(),nums.end());
        int ans=0;
        while (min<=max){
            int mid=min+(max-min)/2;
            if(check(nums,k,mid)){
                ans=mid;
                max=mid-1;
            }
            else{
                min=mid+1;
            }
        } return ans;
    }
};