class Solution {
public:
    vector<vector<string>> ans;
    bool ispalindrome(int l,int r,string a){
        while(l<=r){
            if(a[l]!=a[r])return false;
            l++;r--;
        }
        return true;
    }
    void solve(int st,int end,string a,vector<string> &arr){
       if(st>=a.size()){
        ans.push_back(arr);return;
       }
       for(int i=st;i<=end;i++){
        if(ispalindrome(st,i,a)){
            // if(st+i<a.size()){
               arr.push_back(a.substr(st,i-st+1));
               solve(i+1,end,a,arr);
               arr.pop_back();
            // }
        }
       }
    }
    vector<vector<string>> partition(string s) {
       vector<string> arr;
       solve(0,s.size()-1,s,arr);
       return ans; 
    }
};