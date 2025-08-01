class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26,0);
        int len=0;int maxf=0;
        int l=0;int r=0;int x=0;char ch='0';
        while(l<=r && r<s.size()){
           freq[s[r]-'A']++;
           maxf=max(maxf,freq[s[r]-'A']);
           if(r-l+1-maxf>k){
            freq[s[l]-'A']--;l++;
           }
           len=max(len,r-l+1);
           r++;
        }
        return len;
    }
};