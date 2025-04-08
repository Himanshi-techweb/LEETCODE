class Solution {
public:
    int minimumOperations(vector<int>& arr) {
       map<int,int> check;
       for(auto x:arr) {
        check[x]++;
       }int ans=0;
       while(true){
         bool distinct=true;
         for(auto [x,freq]:check){
            if(freq>1)distinct=false;
         }
         if(distinct)break;
         int remove=min((int)arr.size(),3);
         for(int i=0;i<remove;i++){
            check[arr[i]]--;
         }
         arr.erase(arr.begin(),arr.begin()+remove);
         ans++;
       }
       return ans;
    }
};