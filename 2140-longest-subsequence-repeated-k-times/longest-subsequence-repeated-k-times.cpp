class Solution {
public:
    string result="";
    bool issubsequence(string &s,string &curr,int k){
        int i=0;int j=0;
        while(j<k*curr.size() && i<s.size()){
            if(s[i]==curr[j%curr.size()]){
                j++;
            }
            i++;
        }
        return j==k*curr.size();
    }
    bool backtracking(string &s ,string &curr,vector<int> &temprequire,vector<bool> &canuse,int maxlen,int k){

        // if(curr.size()>maxlen)return;
        // if(curr.size()>result.size() || (curr.size()==result.size() && curr>result ) && issubsequence(s,curr,k)){
        //     result=curr;
        //     return;
        // }
        if(curr.size()==maxlen && issubsequence(s,curr,k)){
            result=curr;
            return true;
        }

        //
        for(int i=25;i>=0;i--){
            if(!canuse[i] || temprequire[i]==0)continue;
            curr.push_back(i+'a');
            temprequire[i]--;
            if(backtracking(s,curr,temprequire,canuse,maxlen,k))return true;
            curr.pop_back();
            temprequire[i]++;

        }
        return false;
    }
    string longestSubsequenceRepeatedK(string s, int k) {
        int n=s.size();
        int maxlen=n/k;
        vector<int> freq(26,0);
        vector<int> require(26,0);
        vector<bool> canuse(26,0);
        for(int i=0;i<n;i++){
           freq[s[i]-'a']++;
        
        }

        //check if it can be use 
        for(int i=0;i<26;i++){
            if(freq[i]>=k){
               canuse[i]=true;
               require[i]=freq[i]/k;

            }
        }

        //then maxlrn
        
        for(int l=maxlen;l>=0;l--){
            string curr="";
            vector<int> temprequire=require;
            if(backtracking(s,curr,temprequire,canuse,l,k))return result;

        }
        return result;
    }
};