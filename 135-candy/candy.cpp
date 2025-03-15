class Solution {
public:
    int candy(vector<int>& rating) {
      int n=rating.size();
      vector<int> arr(n,1);
      //left to right;
      for(int i=1;i<n;i++){
        if(rating[i]>rating[i-1]){
            arr[i]=arr[i-1]+1;
        }
      } 
      //right to left
      for(int i=n-2;i>=0 ;i--){
        if(rating[i]>rating[i+1]){
            arr[i]=max(arr[i],arr[i+1]+1);
        }
      }
      int sum=accumulate(arr.begin(),arr.end(),0);
      return sum; 
    }
};