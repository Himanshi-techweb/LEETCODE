class Solution {
public:
    vector<int> rc={-1,0,1};
    int solve(int i,int k,vector<int> &arr,unordered_map<int,int> &st,unordered_map<int,unordered_map<int,int>> &check){
        if(i>=arr.size()-1)return true;
        if(check.find(i)!=check.end() && check[i].find(k)!=check[i].end())return check[i][k];
        bool ans=false;
        for(auto it:rc){
            int jump=k+it;
            if(jump>0 && st.find(arr[i]+jump)!=st.end() &&  solve(st[arr[i]+jump],jump,arr,st,check))return true;
        }  
       return check[i][k] =false;
    }
    bool canCross(vector<int>& stones) {
       unordered_map<int,int> st;
       unordered_map<int,unordered_map<int,int>> check;
       for(auto int i=0;i<stones.size();i++)st[stones[i]]=i;
       if(stones[1]!=1)return false;
       return solve(0,0,stones,st,check); 
    }
};