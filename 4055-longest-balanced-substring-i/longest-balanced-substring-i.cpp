class Solution {
public:
    int longestBalanced(string s) {
        int ans=INT_MIN;
       for(int i=0;i<s.size();i++){
        unordered_map<char,int> check;
        
        for(int j=i;j<s.size();j++){
            check[s[j]]++;
            int mini=INT_MAX;int maxi=INT_MIN;
            for(auto it:check){
                mini=min(mini,it.second);
                maxi=max(maxi,it.second);
            }

            if(mini==maxi){
                ans=max(ans,j-i+1);
            }
        }
       
       } 
        return ans;
    }
};