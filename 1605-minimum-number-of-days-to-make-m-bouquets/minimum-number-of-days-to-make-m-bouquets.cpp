class Solution {
public:
    bool solve(int mid,int m,int k,vector<int>&arr){
        int cnt_flower=0;
        int bouquet=0;
        for(int i=0;i<arr.size();i++){
            
            if(arr[i]>mid){
                //discontinue all flower make cnt_flower==0
                cnt_flower=0;
            }
            else cnt_flower++;
            if(cnt_flower>=k){
                bouquet++;
                cnt_flower=0;
            }
               
        }
        return bouquet>=m;
        
        
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int l=1;
        int h=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(solve(mid,m,k,bloomDay)){
                ans=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};