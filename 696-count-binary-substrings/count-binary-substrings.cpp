class Solution {
public:
    int countBinarySubstrings(string s) {
    
      int prev_s=0;int prev_e=0;
      int curr_s=0;
      int i=1;int count=0;
      while(i<s.size()){
         if(s[i]!=s[prev_s])break;
         i++;
      }
      prev_e=i-1;
      curr_s=i;
      while(i<s.size()){
        if(s[i]!=s[curr_s]){
           count+= min(prev_e-prev_s+1,i-curr_s);
           prev_s=curr_s;
           prev_e=i-1;
           curr_s=i;
        }
        i++;
      }
      count+= min(prev_e-prev_s+1,i-curr_s);
      return count;  
    }
};