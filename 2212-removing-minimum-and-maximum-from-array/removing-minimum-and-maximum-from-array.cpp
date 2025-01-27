class Solution {
public:
    vector<int> solve_max(vector<int> &nums){
        if(nums.size()==0 || nums.size()==1)return {0,0};
        int max_id=0;
        int min_id=0;
        int i=0;
        vector<int> v;
        while(i<nums.size()){
            if(nums[i]>nums[max_id]){
                max_id=i;
            }
            if(nums[i]<nums[min_id]){
                min_id=i;
            }
            i++;
        }
        v.push_back(min_id);
        v.push_back(max_id);
        return v;
    }
    int solve(int min,int max,vector<int> &nums,int &n,int id){
        if(min>max)swap(min,max);
        //both front
        int ans_bfront=max+1;
        //both back
        int ans_bback=n-min;
        //max front min back
        int ans_maxf_minb=min+n-max+1;
        int ans_maxb_minf=max-min+n+1;
        return std::min({ans_bfront,ans_maxf_minb,ans_bback,ans_maxb_minf});

    }
    int minimumDeletions(vector<int>& nums) {
      vector<int> min_max=solve_max(nums);
      int n=nums.size();
      int min=min_max[0];
      int max=min_max[1];  
      int ans=0;
      int id=std::max(min,max);
      //both front;
      return solve(min,max,nums,n,id);
    }
};