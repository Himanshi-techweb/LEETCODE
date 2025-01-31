class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        stack<int> q;
        int i=0;int j=1;
        while(i<target.size() && j<=n){
          q.push(j);
          ans.push_back("Push");
          int x=q.top();
          if(x!=target[i]){
            q.pop();
            ans.push_back("Pop");
          }
          else{
            i++;
          }
        
        j++;
        }
        return ans;
    }
};