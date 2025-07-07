class Solution {
public:
    string reorganizeString(string s) {
       unordered_map<char,int> check;
       string re="";
       priority_queue<pair<int,char>> q;
       for(int i=0;i<s.size();i++){
        check[s[i]]++;
        if(check[s[i]]>(s.size()+1)/2)return "";
       }
       for(auto [ch,freq]:check){
        q.push({freq,ch});
       }
       pair<int,char> i={0,'0'};
       while(!q.empty()){
          auto [cnt,ch]=q.top();q.pop();
          re+=ch;
          cnt--;
          if(i.first>0){
            q.push(i);
          }
          i={cnt,ch};
       }
       return (re.size()==s.size())?re:""; 
    }
};