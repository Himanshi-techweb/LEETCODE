class Solution {
public:
    int characterReplacement(string s, int k) {
       int l=0;int r=0;int max_f=0; int max_l=0;
       int check[26]={0};
       while(r<s.length()){
           check[s[r]-'A']++;
           max_f=max(max_f,check[s[r]-'A']);
           if((r-l+1)-max_f <= k){
            max_l=max(max_l,r-l+1);
           }
           else{
            check[s[l]-'A']--;
            l++;
           }
           r++;
       }
       return max_l;
    }
};