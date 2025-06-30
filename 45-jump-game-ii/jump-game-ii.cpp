class Solution {
public:
    int jump(vector<int>& arr) {
     int cnt=0;
     int l=0;int r=0;
     while(r<arr.size()-1){
        int farthest=0;
        for(int i=l;i<=r;i++){
           farthest=max(farthest,i+arr[i]);
        }
        l=r+1;
        r=farthest;
        cnt++;
     }
     return cnt;  
    }
};