class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        if(n==0 || n==1)return n;
        vector<int> arr(256+1,0);
        int len=0;
        int l=0;int r=0;
        while(l<=r && r<s.size()){
        while(arr[(unsigned char)s[r]]>0){
          arr[(unsigned char)s[l]]--;
          l++;
        }
        arr[(unsigned char)s[r]]++;
        len=max(len,r-l+1);
        r++;
       }
       return len;
    }
};