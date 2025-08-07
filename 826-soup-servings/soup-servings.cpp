class Solution {
public:
    vector<vector<int>> rc={{100,0},{75,25},{50,50},{25,75}};
    unordered_map<int,unordered_map<int,double>> check;
    double solve(int A,int B){
        if(A<0)A=0;if(B<0)B=0;
        if(A==0 && B!=0)return 1;
        else if(A==0 && B==0)return 0.5;
        else if(A!=0 && B==0)return 0;
        if(check.find(A)!=check.end() && check[A].find(B)!=check[A].end())return check[A][B];
        double prob=0;
        for(auto it:rc){
            prob=prob+0.25*solve(A-it[0],B-it[1]);
        }
        return check[A][B]=prob;
    }
    double soupServings(int n) {
        if(n>=5000)return 1.0;
       return solve(n,n); 
    }
};