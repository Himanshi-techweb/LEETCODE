class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string curr=strs[0];
        for(int i=1;i<strs.size();i++){
           int len=min(curr.size(),strs[i].size());
           int j=0;
           while(j<len && curr[j]==strs[i][j])j++;
           curr=strs[i].substr(0,j);
        }
        return curr;
    }
};