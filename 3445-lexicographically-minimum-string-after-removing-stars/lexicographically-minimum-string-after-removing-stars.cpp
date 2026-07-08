struct cmp{
    bool operator()(const pair<char,int>&a,const pair<char,int>&b) const{
        if(a.first==b.first)return a.second<b.second;
        return a.first>b.first;
    }
};
class Solution {
public:
    string clearStars(string s) {
    
       priority_queue<pair<char,int>,vector<pair<char,int>>,cmp> q;
       int cnt=0;
       vector<bool> arr(s.size(),false);
       for(int i=0;i<s.size();i++){
           auto ch=s[i];
           if(ch=='*' && !q.empty()){
               arr[q.top().second]=true;
               q.pop();
               cnt++;
           }
           else if(ch>='a' && ch<='z'){
               q.push({ch,i});
           }
       }
       cout<<q.size()<<endl;
       string ans="";
       for(int i=0;i<s.size();i++){
          if(arr[i]==true || s[i]=='*')continue;
          else ans+=s[i];
       }
       
       
       return cnt==0?s:ans;
       
    }
};