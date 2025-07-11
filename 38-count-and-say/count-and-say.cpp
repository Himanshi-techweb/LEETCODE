class Solution {
public:
    string solve(int n){
        if(n==1)return "1";
        string say=solve(n-1);
        string re="";
        char pre=say[0];int cnt=1;
        for(int i=1;i<say.size();i++){
            char ch=say[i];
            if(ch==pre){
              cnt++;
            }
            else{
                re=re+to_string(cnt)+pre;
                cnt=1;
                pre=ch;
            }
        }
        re=re+to_string(cnt)+pre;
        return re;
    } 
    string countAndSay(int n) {
        return solve(n);
    }
};