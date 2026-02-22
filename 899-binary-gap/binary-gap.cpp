class Solution {
public:
    int binaryGap(int n) {
        int start=-1;int end=0;int ans=0;
        while(n>0){
            int rem=n%2;
            if(rem==1){
                ans=max(ans,start);
                start=1;
            }
            else if(start!=-1){
               start++; 
            }
            n=n/2;
        }
        return ans;
    }
};