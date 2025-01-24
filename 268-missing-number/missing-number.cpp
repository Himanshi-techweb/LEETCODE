class Solution {
public:
    int missingNumber(vector<int>& arr) {
    //   sort(arr.begin(),arr.end());
    //   int x=0;
    //   for(int i=0;i<arr.size();i++){
    //    if(arr[i]!=i){
    //     return i;
    //    }
    //    x=i;
    //   }return x+1;




    //optimal
    int n=arr.size();
    int sum=n*(n+1)/2;
    for(auto i:arr){
        sum=sum-i;
    }
    return sum;
    }
};