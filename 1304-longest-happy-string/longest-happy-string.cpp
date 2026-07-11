class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> q;
        string result="";
        if(a>0)q.push({a,'a'});
        if(b>0)q.push({b,'b'});
        if(c>0)q.push({c,'c'});
        while(!q.empty()){
           auto currcount=q.top().first;
           auto currchar=q.top().second;
           q.pop();
           if(result.size()>1 && (result[result.size()-1]==currchar && result[result.size()-2]==currchar)){
            if(q.empty())break;
            auto nextcount=q.top().first;
            auto nextchar=q.top().second;
            q.pop();
            result+=nextchar;
            nextcount--;
            if(nextcount>0)q.push({nextcount,nextchar});
            if(currcount>0 )q.push({currcount,currchar});
            
           } 
           else{
            currcount--;
            if(currcount>0){
                q.push({currcount,currchar});
            }
            result+=currchar;
           }
        }
        

        return result;
    }
};