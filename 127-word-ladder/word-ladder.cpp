class Solution {
public:
    bool checkfunc(string str,set<string> &check,vector<char> &alpha,queue<pair<string,int>> & q,string end,int freq){ 
      string copy=str;
      bool occur=false;
      for(int i=0;i<str.size();i++){
        for(int j=0;j<alpha.size();j++){
            str=copy;
            str[i]=alpha[j];
            if(check.find(str)!=check.end()){
              if(str==end){
                return true;
              }
              check.erase(str);
              q.push({str,freq+1});
            }
        }
      }
      return false;  
    }
    int ladderLength(string beginWord, string endWord, vector<string>& arr) {
      vector<char> alpha={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
      set<string> check;
      queue<pair<string,int>> q;
      q.push({beginWord,1});
      for(string x:arr){
        check.insert(x);
      }
      int ans=0;
      bool occur=false;
      while(!q.empty()){
        // pair<string,int> temp=q.front();
        string str=q.front().first;
        int freq=q.front().second;
        q.pop();
        if(checkfunc(str,check,alpha,q,endWord,freq)==true){
            return freq+1;
        }
      }  
      return 0;
    }
};