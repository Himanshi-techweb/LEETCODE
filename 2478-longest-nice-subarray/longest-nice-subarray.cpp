class Solution {
public:
    int longestNiceSubarray(vector<int>& num) {
     int x=num.size();
     if(x<=1)return 1;
     int l=0;int r=0;int check=0;int ans=0;
     while(l<=r && r<x){
        while((check & num[r])!=0){
           check=check^num[l];
           l++; 
        }
        check=check|num[r];
        ans=max(r-l+1,ans);
        r++;
     }return ans;   
    }
};