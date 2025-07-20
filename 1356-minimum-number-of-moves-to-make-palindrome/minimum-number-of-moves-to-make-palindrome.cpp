class Solution {
public:
    int minMovesToMakePalindrome(string s) {
       int l=0;int r=s.size()-1;
       int swaps=0;
       while(l<=r){
        if(s[l]==s[r]){
            l++;r--;
        }
        else{
            int k=r;
            while(s[k]!=s[l])k--;
            if(k==l){
                swap(s[k],s[k+1]);
                swaps++;
            }
            else{
                for(;k<r;k++){
                    swap(s[k],s[k+1]);
                    swaps++;
                }
            }
        }
       }
       return swaps;
    }
};