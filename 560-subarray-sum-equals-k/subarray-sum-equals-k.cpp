class Solution {
    //   int sum=0;
    //   int x=0;
    //   for(int i=0;i<arr.size();i++){
    //     if(sum<k){
    //         sum+=arr[i];
    //     }
    //     if(sum>k){
    //         sum-=arr[i];
    //     }
    //     else{
    //         x++;
    //     }
    //   } return x-1; 
public:
    int subarraySum(vector<int>& arr, int k) {
      if(arr.size()==0)return 0;
      if(arr.size()==1)return arr[0]==k;
      unordered_map<int,int> check;
      int count=0;
      int sum=0;
      check[0]=1;
      for(auto x:arr){
         sum+=x;
        if(check.find(sum-k)!=check.end()){
            count+=check[sum-k];
        }
        check[sum]++;
      }
      return count++;
    }
};