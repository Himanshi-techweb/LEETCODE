class Solution {

public://a,cs=pj;b,cs=pj+1;c,cs=pj-1 check if cs there or not if yes then it is csidx
    // bool solve(vector<int> &arr,int pj,int cs,unordered_map<int,int> &check,unordered_map<int,unordered_map<int,bool>> &dp){//n-1
    //     // if(pj<=0|| check.find(cs)==check.end() )return false;
    //     if(cs==arr.back())return true;
    // //    if(dp[cs].count(pj)) return dp[cs][pj];
    //     bool check_a=false;
    //     bool check_b=false;
    //     bool check_c=false;
    //     if(pj-1>0 && check.find(cs+pj-1)!=check.end()){
    //         check_a=solve(arr,pj-1,cs+pj-1,check,dp);
    //     }
    //     if(check.find(cs+pj)!=check.end()){
    //         check_b=solve(arr,pj,cs+pj,check,dp);
    //     }
    //     if(check.find(cs+pj+1)!=check.end()){
    //         check_c=solve(arr,pj+1,cs+pj+1,check,dp);
    //     }
    //     return check_a || check_b || check_c;
    // }
    bool solve(int curr_idx,int pj,vector<int> &stones,unordered_map<int,int> &check,unordered_map<int,unordered_map<int,bool>> &check_2){
        if(curr_idx==stones.size()-1)return true;
        if(check_2[curr_idx].count(pj))return check_2[curr_idx][pj];
        bool result=false;
        for(int nj=pj-1;nj<=pj+1;nj++){
            if(nj>0){
              int next_stone=stones[curr_idx]+nj;
              if(check.find(next_stone)!=check.end()){
                result=result|| solve(check[next_stone],nj,stones,check,check_2);
              }
              
            }
            
        }return check_2[curr_idx][pj]=result;
    }
    bool canCross(vector<int>& stones) {
        unordered_map<int,int> check;
        unordered_map<int,unordered_map<int,bool>> dp;
        unordered_map<int,unordered_map<int,bool>> check_2;
        if(stones[1]!=1)return false;
       for(int i=0;i<stones.size();i++){
        check[stones[i]]=i;
       }
    //    return solve(stones,0,0,check,dp); 
     return solve(0,0,stones,check,check_2);
    }
};