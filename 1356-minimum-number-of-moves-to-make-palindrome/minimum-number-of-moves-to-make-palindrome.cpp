class Solution {
public:
    int minMovesToMakePalindrome(string s) {
       int l=0;int h=s.size()-1;
       int swaps=0;
       while(l<=h){
         if(s[l]==s[h]){
            l++;h--;
         }
         else{
            int k=h;
            while(l<h && s[k]!=s[l])k--;
            if(k==l){
                swap(s[k],s[k+1]);
                swaps++;
                continue;
            }
            else{
              for(int i=k;i<h;i++){
                swap(s[i],s[i+1]);
                swaps++;
              }
            }
            l++;h--;
         }
       } 
       return swaps;
    }
};