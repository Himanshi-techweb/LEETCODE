class Solution {
public:
    int count(string s,int l,int r){
        int count_0=0;int count_1=0;
        for(int i=l;i<=r;i++){
        if(i%2==0){
            count_0+=(s[i]-'0'==0?0:1);
            count_1+=(s[i]-'0'==1?0:1);
        }
        else{
           count_0+=(s[i]-'0'==1?0:1); 
           count_1+=(s[i]-'0'==0?0:1);
        }
        } 
        return min(count_0,count_1);  
    }
    int minFlips(string s) {
      int mini=INT_MAX;

      int diff1=0;
      int diff2=0;
      for(int i=0;i<s.size();i++){
        //for pattern
        if(i%2==0){
           if(s[i]!='1')diff1++;
           else diff2++;
        }
        else{
            if(s[i]!='1')diff2++;
            else diff1++;
        }
      }
      mini=min(mini,min(diff1,diff2));
      //pattern 1:: 1010......
      //pattern 2:: 0101......
      string t=s+s;
      
      int l=0;int r=s.size()-1;
      while(r<t.size()-1){
        //check for l
        if(l%2==0){
          if(t[l]=='0')diff1--;
          else diff2--; 
        }
        else{
          if(t[l]=='0')diff2--;
          else diff1--;  
        }
        r++;l++;
        //check for r
        if(r%2==0){
           if(t[r]=='0')diff1++;
           else diff2++;  
        }
        else{
            if(t[r]=='0')diff2++;
            else diff1++; 
        }
        // l++;
        mini=min(mini,min(diff1,diff2));
        // l++;r++;
      }
      return mini;
    }
};