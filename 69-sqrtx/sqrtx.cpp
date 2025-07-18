class Solution {
public:
    int mySqrt(int x) {
        if(x==0)return 0;
        if(x==1)return 1;
        int low=1;
        int high=x;int ans=1;
        while(low<=high){
            long long mid =low + (high-low)/2;
            if(mid*mid==x)return mid;
            if(mid*mid >x)high=mid-1;
            else {
                ans=mid;
                low=mid+1;
            }
        }
        return ans; 
    }
};