class Solution {
public:
    int sum_calc(int i){
        int sum=0;
        while(i>0){
            sum+=i%10;
            i=i/10;
        }
        return sum;
    }
    int countLargestGroup(int n) {
     unordered_map<int,int>check;
     for(int i=1;i<=n;i++){
        int sum=sum_calc(i);
        check[sum]++;
     }  int count=0;int ans=0;
     for(auto [x,freq]:check){
        if(freq>count){
            count=freq;
            ans=1;}
        else if(freq==count)ans++;
     } 
     return ans;
    }
};