class Solution {
public:
    int minCost(string s, vector<int>& neededTime) {
       int i=0;int j=1;int cnt=0;
       while(i<s.size() && j<s.size()){
         if(s[i]==s[j]){
            if(neededTime[i]<=neededTime[j]){
                cnt+=neededTime[i];
                i=j;
                j++;
            }
            else{
              cnt+=neededTime[j];
              j++;
            }
         }
         else{
            i=j;j++;
         }
       }
       return cnt; 
    }
};