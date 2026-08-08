class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        vector<int> right(word1.size(),0);
        int i=word1.size()-1;int j=word2.size()-1;
        int r=0;
        while(i>=0 ){
            if(j>=0 && word1[i]==word2[j]){
                r++;
                j--;
            }
            right[i]=r;
            i--;
        }
        bool change=true;
        vector<int> ans;
        i=0;j=0;
        while(i<word1.size() && j<word2.size()){
            if(word1[i]==word2[j]){
                ans.push_back(i);
                
                j++;
            }
            else if(change && i+1<word1.size() && right[i+1]>=word2.size()-j-1){
                ans.push_back(i);
                change=false;
                j++;
            }
            i++;
        }
        cout<<j;
        if(j==word2.size())return ans;
        return {}; 
    }
};