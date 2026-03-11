class Solution {
public:
    int bitwiseComplement(int n) {
      vector<int> arr;
      int sum=0;
      if(n==0)return 1;
      if(n==1)return 0;
      while(n>0){
        int r=n%2;
        n=n/2;
        if(r==0)arr.push_back(1);
        else arr.push_back(0);
        
      } 
    //   reverse(arr.begin(),arr.end());
      for(int i=0;i<arr.size();i++){
        sum=sum+(arr[i]*(1<<i));
      } 
      return sum;
    }
};