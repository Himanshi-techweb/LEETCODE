class Solution {
public:
    string solve1(string &s){
        vector<int> dp(s.size(),0);int l=0;int r=0;int maxi=0;
        for(int i=0;i<s.size();i++){
            //traverse i to left and i to right
            int left=i-1;int right=i+1;
            while(left>=0 && right<s.size() && s[left]==s[right]){
                dp[i]=right-left+1;
                if(maxi<dp[i]){
                l=left;
                r=right;
                maxi=r-l+1;
                }            
                left--;
                right++;            
            }    
        }
        return s.substr(l,r-l+1);
    }
    string solve2(string s){
        int maxi=0;
        int l=0;int r=0;
        for(int i=0;i<s.size();i++){
            int left=i;
            int right=i+1;
            while(left>=0 && right<s.size() && s[left]==s[right]){
                if(maxi<right-left+1){
                    l=left;
                    r=right;
                    maxi=r-l+1;
                }
                left--;
                right++;
            }
        }
        return s.substr(l,r-l+1);
    }
    string longestPalindrome(string s) {
        string str1=solve1(s);
        string str2=solve2(s);
        cout<<str1<<" "<<str2<<endl;
        if(str1.size()>str2.size())return str1;
        return str2;
    }
};