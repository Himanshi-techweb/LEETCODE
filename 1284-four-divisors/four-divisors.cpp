class Solution {
public:
    bool isprime(int x){
        if(x<2)return false;
        for(int i=2;i*i<=x;i++){
            if(x%i==0)return false;
        }return true;
    }
    int iscubic(int n){
        int x=round(cbrt(n));
        if(x*x*x==n && isprime(x)){
            return 1+x+x*x+x*x*x;
        }
        return 0;
    }
    int sumFourDivisors(vector<int>& nums) {
      int ans=0;
      for(int i=0;i<nums.size();i++){
        int k=nums[i];
        int cube=iscubic(k);
        if(cube!=0 ){
            ans+=cube;
            continue;
        }
            int check=1+k;
            int count=2;
            for(int j=2;j*j<=k;j++){
            if(k%j==0 ){
                int g=k/j;
                if(j==g){
                    count+=1;
                    check+=j;
                }
                if(isprime(g) && isprime(j)){
                    count+=2;
                    check+=j;
                    check+=g;
                }
            }
            if(count>4)break;
           }
           if(count==4) ans+=check; 
        }
      return ans;
    }
};