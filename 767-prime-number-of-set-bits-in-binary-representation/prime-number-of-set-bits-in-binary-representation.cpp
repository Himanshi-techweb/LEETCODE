class Solution {
public:
    
    const int N=100000;
    void check_prime(vector<bool> &prime,int n){
         prime[0]=false;
         prime[1]=false;
         for(int i=2;i*i<=n;i++){
            if(prime[i]){
                for(int j=i*i;j<=n;j+=i){
                    prime[j]=false;
                }
            }
         }
    }
    int countPrimeSetBits(int left, int right) {
        vector<bool> prime(N+2,true);
        // prime.resize(N+2,true);
        check_prime(prime,N+2);

        int ans=0;
        //1e4
        for(long long i=left;i<=right;i++){
            //each i
            if(prime[__builtin_popcount(i)])ans++;
        }
        return ans;
        //  return 0;
    }
};