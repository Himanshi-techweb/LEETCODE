class Solution {
public:
    bool check(vector<int> &candies,long long mid,long long k){
        unsigned long long count=0;
        for(auto x:candies){
           count+=(x/mid);
           if(count>=k)return true;
        }
        return false;
    }
    int maximumCandies(vector<int>& candies, long long k) {
      if(accumulate(candies.begin(),candies.end(),0ULL)<k)return 0;
     
      unsigned long long l=1;unsigned long long r=*max_element(candies.begin(),candies.end());
      unsigned long long ans=0;
      while(l<=r){
        unsigned long long mid=l+(r-l)/2;
        if(check(candies,mid,k)){
            ans=mid;
            l=mid+1;
        }
        else{
            r=mid-1;
        }
      }  return ans;
    }
};