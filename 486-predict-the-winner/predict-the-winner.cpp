class Solution {
public:
    //try it with 2 option take back or end ok
    // also check who turn //1 as alice 2 as bob
    //now to erase use start and end index 
    int solve(int s,int e,int turn ,vector<int> &arr){
        if(s>e)return 0;
        int result=(turn==1)?-1:INT_MAX;
        if(turn==1){
            result=max({arr[s]+solve(s+1,e,0,arr),arr[e]+solve(s,e-1,0,arr)});    
        }
        else{   
            result=min({solve(s+1,e,1,arr),solve(s,e-1,1,arr)});    
        }
        return result;
    }
    bool predictTheWinner(vector<int>& nums) {
        int diff=0;
        long long tot=accumulate(nums.begin(),nums.end(),0);
        int ans=solve(0,nums.size()-1,1,nums);
        cout<<tot-ans<<endl;
        return (tot-ans<=ans);
    }
};