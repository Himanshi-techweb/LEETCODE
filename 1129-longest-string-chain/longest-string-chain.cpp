class Solution {
public:
    bool ischeck(string &before,string &after){
        int i=0;
        int j=0;
        bool change=false;
        while(j<after.length()){
            if(i<before.length() && before[i]==after[j])i++;
            else {
                if(change)return false;
                change=true;
            }j++;
        }
        return true;
    }
    int longestStrChain(vector<string>& word) {
       sort(word.begin(),word.end(),[](const string & a,const string &b){
        return a.length()<b.length();
       });
       int n=word.size();
       if(n==0 || n==1)return n;
       vector<int> dp(n,1); 
       vector<int> check(n);
       for(int i=0;i<n;i++){
          check[i]=i;
       }int k=0;int maxi=0;
       for(int i=1;i<n;i++){
        string x1=word[i];
        for(int j=0;j<i;j++){
            string x2=word[j];
            if(x2.length()+1==x1.length() && ischeck(x2,x1 )&& dp[j]+1>dp[i]){
                dp[i]=dp[j]+1;
                check[i]=j;
            }
        }
        if(dp[i]>maxi){
            maxi=dp[i];
            k=i;
        }
       }
       return maxi;
    }
};