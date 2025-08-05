class Solution {
public:
    unordered_map<vector<bool>,int>it;
    int gcd(int a,int b){
        if(a==0)return b;
        if(b==0)return a;
        if(a>b)return gcd(a%b,b);
        else return gcd(b%a,a);
    }
    int solve(int count,vector<int> &arr,vector<bool> &visit){
       int max_score=0; 
       if(it.find(visit)!=it.end())return it[visit];
       for(int i=0;i<arr.size()-1;i++){
        if(visit[i]==true)continue;
        for(int j=i+1;j<arr.size();j++){
            if(visit[j]==true)continue;
            visit[i]=true;visit[j]=true;
            int score=count*gcd(arr[i],arr[j]);
            int afterscore=solve(count+1,arr,visit);
            visit[i]=false;visit[j]=false;
            max_score=max(max_score,score+afterscore);
        }
       }
       return it[visit]= max_score;
    }
    int maxScore(vector<int>& nums) {
       vector<bool> visit(nums.size(),false);
       return solve(1,nums,visit);
    }
};