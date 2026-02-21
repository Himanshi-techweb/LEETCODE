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
            long long k=i;
            int count=0;
            //logn
            while(k>0){
                int rem=k%2;
                count+=(rem==1)?1:0;
                k=k/2;
            }
            cout<<count<<" "<<prime[count]<<" "<<i<<endl;
            if(prime[count])ans++;
        }
        return ans;
        //  return 0;
    }
};