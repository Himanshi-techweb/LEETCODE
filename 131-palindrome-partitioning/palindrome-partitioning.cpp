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
    void solve(int st,string a,vector<string> &arr){
       if(st>=a.size()){
        ans.push_back(arr);return;
       }
       for(int i=st;i<a.size();i++){
        if(ispalindrome(st,i,a)){
               arr.push_back(a.substr(st,i-st+1));
               solve(i+1,a,arr);
               arr.pop_back();
        }
       }
    }
    vector<vector<string>> partition(string s) {
       vector<string> arr;
       solve(0,s,arr);
       return ans; 
    }
};