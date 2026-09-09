class Solution {
public:
    long long countCommas(long long n) {
        if(n<1000)return 0;
        long long cnt=0;
        if(n>=1000LL){
            long long count=min(n,999999LL);
            cnt+=(1LL*(count-1000LL+1));
        }
        if(n>=1e6){
            long long count=min(n,999999999LL);
            cnt+=(2LL*(count-1000000LL+1));
        }
        if(n>=1e9){
            long long count=min(n,999999999999LL);
            cnt+=(3LL*(count-1000000000LL +1));

        }
        if(n>=1e12){
            long long count=min(n,999999999999999LL);
            cnt+=(4LL*(count-1000000000000LL +1));
        }
        if(n==1e15){
            cnt+=5;
        }
        return cnt;
    }
};