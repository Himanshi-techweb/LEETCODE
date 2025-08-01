class Solution {
public:
    int longestOnes(vector<int>& s, int k) {
       int x=0;
       int len=0;
       int l=0;int r=0;
       while(l<=r && r<s.size()){
         if(x>k){
            if(s[l]==0)x--;
            l++;
         }
         else {
            if(s[r]==0)x++;
            if(x<=k){
              len=max(len,r-l+1);
            }  
            r++;
         }
       }
       return len; 
    }
};