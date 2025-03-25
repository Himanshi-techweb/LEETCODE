class Compare{
    public:
   static bool compare(const vector<int> &a, const vector<int> &b){
     if(a[0]<b[0])return true;
     else if(a[0]==b[0])return a[1]>b[1];
     return false;
   }
};
class Solution {//start=0,end=1;
public:
    bool solve(vector<vector<int>> &arr){
        sort(arr.begin(),arr.end(),Compare :: compare);
        int overlap=0;int line=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i][1]==0){
                overlap++;
            }
            else{
                overlap--;
                if(overlap==0)line++;
            }
        }
        return line>=3;
    }
    bool checkValidCuts(int n, vector<vector<int>>& rect) {
       vector<vector<int>> arrx;
       vector<vector<int>> arry;
       for(int i=0;i<rect.size();i++){
        arrx.push_back({rect[i][0],0});
        arrx.push_back({rect[i][2],1});
        arry.push_back({rect[i][1],0});
        arry.push_back({rect[i][3],1});
       }
       bool x=solve(arrx);
       bool y=solve(arry);
       return x||y; 
    }
};