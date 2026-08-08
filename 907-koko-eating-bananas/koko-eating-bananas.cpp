class Solution {
public:
    bool solve(int mid,vector<int>&piles,int k){
        long long cnt=0;
        for(int i=0;i<piles.size();i++){
            cnt+=(piles[i]/mid);
            if(piles[i]%mid!=0)cnt+=1;
            if(cnt>k)return false;
        }
        cout<<mid<<" "<<cnt<<endl;
        return cnt<=k;
    }
    int minEatingSpeed(vector<int>& piles, int k) {
        sort(piles.begin(),piles.end());
        int l=1;int h=piles[piles.size()-1];
        int ans=piles[0];
        while(l<=h){
            int mid=(l+h)/2;
            if(solve(mid,piles,k)){
                ans=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return ans;


    }
};