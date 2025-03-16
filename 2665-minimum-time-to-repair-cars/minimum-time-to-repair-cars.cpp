class Solution {
public:
    bool check(vector<int> &arr,long long k,int car){
        long long count=0;
        for(auto x:arr){
            count=count+(long long)sqrt(k/x);
            if(count>=car)return true;
        }return false;
    }
    long long repairCars(vector<int>& ranks, int cars) {
       long long min=1;
       long long x=*min_element(ranks.begin(),ranks.end());
       long long max=(long long)cars*cars*x;
       long long ans=0;
       while(min<=max){
         long long mid=min+(max-min)/2;
         if(check(ranks,mid,cars)){
            ans=mid;
            max=mid-1;
         }
         else{
            min=mid+1;
         }
       }
       return ans;
    }
};