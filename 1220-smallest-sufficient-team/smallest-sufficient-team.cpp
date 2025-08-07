class Solution {
public:
    int m;int n;int target;
    vector<int> result;
    unordered_map<int,unordered_map<int,int>> dp;
    void solve(int i,vector<int> &people_skill,vector<int> &temp,int mask){
            if(mask==target){
                if(result.size()==0 || result.size()>temp.size()){
                    result=temp;
                    return;
                }
            }
        if(i>=people_skill.size())return;   
        // string key=to_string(i)+' '+to_string(mask);
        if(dp.count(i) && dp[i].count(mask) && dp[i][mask]!=-1 && dp[i][mask]<=temp.size())return ;   
        // if(result.size()!=0 && result.size()<temp.size())return;
        solve(i+1,people_skill,temp,mask);
        if((mask| people_skill[i])!=mask){
            temp.push_back(i);
            solve(i+1,people_skill,temp,mask| people_skill[i]);
            temp.pop_back();
        }
        dp[i][mask]=(temp.size()!=0)?temp.size():-1;
    }
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
      int m=req_skills.size();
      int n=people.size();
      
      unordered_map<string,int> skills;
      for(int i=0;i<m;i++){
        skills[req_skills[i]]=i;
      } 
      vector<int> people_skill;
      for(auto i:people){
        int skill_bit=0;
        for(auto skill:i){
          skill_bit=skill_bit | (1<<skills[skill]);
        }
        people_skill.push_back(skill_bit);
      }
      target= (1<<m)-1;
      vector<int> curr;
      int mask=0;
      solve(0,people_skill,curr,mask);
      return result; 
    }
};