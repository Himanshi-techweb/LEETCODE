class Solution {
public:
    vector<vector<string>> ans;
    bool check(string s){
        int l=0;int r=s.size()-1;
        while(l<=r){
            if(s[l]!=s[r])return false;
            l++;r--;
        }
        return true;
    }
    void solve(int i,string s,vector<string> &arr){
       if(i==s.size()){
        ans.push_back(arr);
        return;
       }
       for(int j=i;j<s.size();j++){
        //taken 
        if(check(s.substr(i,j-i+1))){
            arr.push_back(s.substr(i,j-i+1));
            solve(j+1,s,arr);
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