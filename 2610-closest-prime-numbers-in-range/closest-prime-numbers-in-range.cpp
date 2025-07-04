class Solution {
public:
    vector<int> closestPrimes(int l, int r) {
        vector<int> prime(r+1);
        for(int i=2;i<=r;i++)prime[i]=1;
        for(int i=2;i*i<=r;i++){
            if(prime[i]==1){
               for(int j=i*i;j<=r;j+=i)prime[j]=0; 
            }
        }int mini=INT_MAX;int num1=-1;int num2=-1;
        for(int i=l;i<=r;i++){
            if(prime[i]==1){
               num1=i;break; 
            }
        }
        if(num1!=-1){
            for(int i=num1+1;i<=r;i++){
             if(prime[i]==1){
               num2=i;break; 
             }
            }
        }
        
        if(num1==-1 || num2==-1)return {-1,-1};
        mini=num2-num1;int x=num1;int y=num2;
        while(num2<=r){
            int prev=num2;
            for(int i=num2+1;i<=r;i++){
                if(prime[i]==1){
                    num1=num2;
                    num2=i;break;
                }
            }
            if(num2==prev)break;
            if(num2-num1<mini){
                mini=num2-num1;
                x=num1;y=num2;
            }
        }
        // if(num1==num2)return {-1,-1};
        vector<int> ans;
        ans.push_back(x);
        ans.push_back(y); 
        return ans;
    }
};