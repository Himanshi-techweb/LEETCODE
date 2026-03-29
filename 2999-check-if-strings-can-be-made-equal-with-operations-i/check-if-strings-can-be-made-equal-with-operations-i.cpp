class Solution {
public:
    bool solve(int i,int j,string &s1 ,string &s2){
        if(s1==s2)return true;
        if(i>=4 || j>=4)return false;
        if(i+2<4){
           swap(s1[i],s1[i+2]);
           if(solve(i+1,j,s1,s2))return true;
           swap(s1[i],s1[i+2]);
        }
        if(j+2<4){
            swap(s2[j],s2[j+2]);
            if(solve(i,j+1,s1,s2))return true;
            swap(s2[j],s2[j+2]);
        }
        return false;
        
    }
    bool canBeEqual(string s1, string s2) {
        if(solve(0,0,s1,s2))return true;
        return false;
    }
};