class Solution {
public:
    string solve(int n){
        if(n==1)return "1";
        string check=solve(n-1);
        string ans="";
        int cnt=1;char ch=check[0];
        for(int i=1;i<check.size();i++){
            if(check[i]==ch){
                cnt++;
            }
            else{
                ans=ans+to_string(cnt)+ch;
                cnt=1;ch=check[i];
            }
        }
        ans=ans+to_string(cnt)+ch;
        return ans;
    } 
    string countAndSay(int n) {
        return solve(n);
    }
};