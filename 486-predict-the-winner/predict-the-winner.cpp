class Solution {
public:
    //try it with 2 option take back or end ok
    // also check who turn //1 as alice 2 as bob
    //now to erase use start and end index 
    int solve(int s,int e,vector<int> &arr){
        if(s>e)return 0;
        
        int take_s=arr[s]+min(solve(s+1,e-1,arr),solve(s+2,e,arr));
        int take_e=arr[e]+min(solve(s+1,e-1,arr),solve(s,e-2,arr));
        return max(take_s,take_e);
    }
    bool predictTheWinner(vector<int>& nums) {

        long long tot=accumulate(nums.begin(),nums.end(),0);
        int ans=solve(0,nums.size()-1,nums);
        cout<<tot-ans<<endl;
        return (tot-ans<=ans);
    }
};