class Solution {
public:
const long long mod=1e9  +7;
    int countGoodNumbers(long long n) {
      long long expeven=(n+1)/2;
      long long expodd=n/2;
      long long evenbase=5;long long oddbase=4;
      //for calculation even answer;
      long long evenans=1;
      while(expeven>0){
        if(expeven%2==1){
            evenans=(evenans*evenbase)%mod;
        }
        evenbase=(evenbase*evenbase)%mod;
        expeven=expeven/2;
      }
      long long oddans=1;
      while(expodd>0){
        if(expodd%2==1){
            oddans=(oddans*oddbase)%mod;
        }
        oddbase=(oddbase*oddbase)%mod;
        expodd=expodd/2;
      }
      int ans=(evenans*oddans)%mod;
      return ans;
    }
};