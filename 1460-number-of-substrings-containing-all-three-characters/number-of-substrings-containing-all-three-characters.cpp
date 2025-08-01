class Solution {
public:
    int numberOfSubstrings(string s) {
      int cnt_a=0;int cnt_b=0;int cnt_c=0;
      int l=0;int r=0;int cnt=0;
      for(;r<s.size();r++){
        if(s[r]=='a')cnt_a++;
        else if(s[r]=='b')cnt_b++;
        else if(s[r]=='c')cnt_c++;
        ////////
        while(cnt_a>0 && cnt_b>0 && cnt_c>0){
            cnt+=(s.size()-(r));
            if(s[l]=='a')cnt_a--;
            else if(s[l]=='b')cnt_b--;
            else if(s[l]=='c')cnt_c--;
            l++;
        }
      } 
      return cnt; 
    }
};