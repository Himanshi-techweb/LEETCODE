class Solution {
public:
    vector<int> findWordsContaining(vector<string>& arr, char x) {
        vector<int> ans;
       for(int i=0;i<arr.size();i++){
         bool check=false;
         for(auto j:arr[i]){
            if(j==x){
                ans.push_back(i);
                check=true;
            }
            if(check)break;
         }
       } 
       return ans;
    }
};