class Solution {
public:
    int mySqrt(int x) {
        if(x==0)return 0;
        long long ans=0;
        int l=1;int h=x;
        while(l<=h){
            long long mid=l+(h-l)/2;
            long long k=1LL*mid*mid;
            if(k==x)return mid;
            else if(k>x){
                h=mid-1;
            }
            else{
                ans=mid;
                l=mid+1;
            }
        }  
        return ans;
    }
};