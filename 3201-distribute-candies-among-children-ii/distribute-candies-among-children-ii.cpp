class Solution {
public:
    long long distributeCandies(int n, int limit) {
       int mini=max(0,n-2*limit);
       int maxi=min(n,limit);long long cnt=0;
       //c1
       for(int i=mini;i<=maxi;i++){
        int new_n=n-i;
        //c2 && c3
        int minic2=max(0,new_n-limit);
        int maxic2=min(limit,new_n);
        cnt+=(maxic2-minic2+1);
       }
       return cnt;
    }
};