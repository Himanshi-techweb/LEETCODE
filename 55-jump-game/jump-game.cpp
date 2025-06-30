class Solution {
public:
    
    bool canJump(vector<int>& arr) {
       vector<int> dp(arr.size(),-1);
       if(arr.size()==1)return true;
       if(arr[0]==0)return false;int maxi=0;
       for(int i=0;i<arr.size();i++){
         if(i>maxi)return false;
         maxi=max(maxi,arr[i]+i);
       } 
       return maxi>=arr.size()-1;
    }
};