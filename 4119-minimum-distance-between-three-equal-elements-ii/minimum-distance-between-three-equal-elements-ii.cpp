class Solution {
public:
    unordered_map<int,pair<int,int>> st;
    unordered_map<int,int> arr;
    int minimumDistance(vector<int>& nums) {
        //for each number store it occurence in sort manner
        long long ans=-1;
        for(int i=0;i<nums.size();i++){
            int x=nums[i];
            arr[x]++;
            if(arr[x]==1){
                st[x]={i,-1};
            }
            else if(arr[x]==2){
                st[x].second=i;
            }
            else{
                long long y=2LL*(i-st[x].first);
                if(ans==-1 || ans>y)ans=y;
                st[x].first=st[x].second;
                st[x].second=i;
                
            }
        }
        // ans=min(ans,)
        return (int)ans;
    }
};