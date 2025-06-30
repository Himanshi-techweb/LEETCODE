class Solution {
public:
    // void insertinterval()
    vector<vector<int>> insert(vector<vector<int>>& arr, vector<int>& ni) {
        //insertinterval
        if(arr.size()==0)return {ni};
        vector<vector<int>> ans;
        int i=0;bool there=false;
        while(i<arr.size()){
           if(arr[i][0]>ni[0]){
            ans.push_back(ni);
            there=true;
            break;
           }
           else{
            ans.push_back(arr[i]);
           }
           i++;
        }if(!there)ans.push_back(ni);
        while(i<arr.size()){
            ans.push_back(arr[i]);
            i++;
        }
        
        //merge
        vector<vector<int>> result;
        vector<int> curr=ans[0];
        for(int i=1;i<ans.size();i++){
           if(curr[1]>=ans[i][0]){
            curr[1]=max(ans[i][1],curr[1]);
           } 
           else{
            result.push_back(curr);
            curr=ans[i];
           }
        }
        result.push_back(curr);
        return result;
    }
};