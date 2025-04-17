class Solution {
public:
    int countPairs(vector<int>& arr, int k) {
        int n=arr.size();int count=0;
        unordered_map<int,vector<int>> check;
        for(int j=0;j<arr.size();j++){
           if(check.find(arr[j])!=check.end()){
             vector<int> curr=check[arr[j]];
             for(auto i:curr){
                if((i*j)%k==0)count++;
             }
           }
           check[arr[j]].push_back(j);
        } 
         return count;
    }
};