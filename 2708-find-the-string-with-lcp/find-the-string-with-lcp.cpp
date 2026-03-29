class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n=lcp.size();
        string s(n,'\0');
        if(lcp[0][0]!=n)return "";
        //current index of string i
        int i=0;
        vector<int> arr(26,0);
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         //abca n=4 and i=1 then i_len n-i
        //         int i_len=n-i;
        //         int j_len=n-j;
        //         if(lcp[i][j]>min(i_len,j_len))return "";
        //         if(lcp[i][j]!=lcp[j][i])return "";
        //     }
        // }
        while(i<n){
           //for first index fill it with 'a' only
            if(i==0)s[i]='a';
           //then after it from next index check if j(0 to i-1) is not equal to 0 if not then fill it with same character as j as increase i
            else{
               //int j=0;
                vector<bool> forbidden(26,false);
                int j=0;
                while(j<i && lcp[i][j]==0){
                forbidden[s[j]-'a']=true;
                j++;
                }
                if(j<i){
                    s[i]=s[j];
                }
                else{
                   char ch='$';
                   for(int k=0;k<26;k++){
                   if(!forbidden[k]){
                    ch=k+'a';
                    break;
                   }
                   }
                   if(ch=='$')return "";
                   s[i]=ch;
                }
               

            }
            i++;
        }
        //verify string lcp
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int cnt=0;int x=i;int y=j;
                while(x<n && y< n && s[x]==s[y]){
                   x++;y++;cnt++;
                }
                if(lcp[i][j]!=cnt)return "";
            }
        }
        return s;
    }
};