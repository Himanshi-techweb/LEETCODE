class Solution {
public:
    // vector<vector<int>> dp;
    unordered_map<int,unordered_map<int,int>> st;
    int solve(int i,int prev,vector<int> &x,vector<int> &y){
        if(i==x.size())return 0;
        if(st.count(i) && st[i].count(prev))return st[i][prev];
        int ans1=2001;
        int ans2=2001;
        int before=(prev==-1)?INT_MIN:prev;
        //try1 
        if(x[i]>before){
            ans1=solve(i+1,x[i],x,y);
        }
        auto nextindex=upper_bound(y.begin(),y.end(),before);
        if(nextindex!=y.end()){
            
            ans2=1+solve(i+1,*nextindex,x,y);
            
        }
        
        return st[i][prev]=min(ans1,ans2);
        
    }
    int makeArrayIncreasing(vector<int>& x, vector<int>& y) {
        sort(y.begin(),y.end());
        
        int ans=solve(0,-1,x,y);
        return ans>=2001?-1:ans;

    }
};