class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
       unordered_set<int> check;int ans=-1;
       for(auto x:arr){
         check.insert(x);
       }
       for(auto i:check){
        int x=i;int count=0;
        if(check.find(x-1)!=check.end()){
            continue;
        }
        else{
            while(check.find(x+1)!=check.end()){
                x=x+1;
                count++;
            }
        }
        ans=max(ans,count);
       } 
       return ans+1; 
    }
};