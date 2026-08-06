class Solution {
public:
    bool work(int t,int i){
        long long ans=1;
        while(i>0){
            int r=i%10;
            ans=ans*r;
            i=i/10;
        }
        return (ans%t)==0;
    }
    int smallestNumber(int n, int t) {
        int i=n;
        while(true){
            if(work(t,i))return i;
            i++;
        }
        return 0;
    }
};