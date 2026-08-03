class Solution {
public:
    const int MOD =1e9 +7;
    long long findpower(int a,long long b){
        if(b==0)return 1;
        long long half=findpower(a,b/2);
        long long result=(half*half)%MOD;
        if(b%2!=0){
            result=(a*result)%MOD;
        }
        return (result)%MOD;
    }
    int countGoodNumbers(long long n) {
        //at odd index there will be 4 number possibility
        //at even index there will be 5 number possibility
        //if n is even then equal multiplication of n/2 (4) and n/2 (5)
        //if n is odd then x=n-1 then x/2 (4) and x/2 (5) and then by 5
        
        long long half1=findpower(4,n/2);
        long long half2=findpower(5,n/2);
        long long result=(half1*half2)%MOD;
        if(n%2!=0){
            result=(result*5)%MOD;
        }
        return result%MOD;    
    }
};