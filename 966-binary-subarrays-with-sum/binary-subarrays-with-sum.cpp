class Solution {
public:
    int numSubarraysWithSum(vector<int>& arr, int goal) {
       unordered_map<int,int> check;
       int sum=0;int cnt=0;
       for(int i=0;i<arr.size();i++){
        sum+=arr[i];
        if(sum==goal)cnt++;
        if(check.find(sum-goal)!=check.end()){
            cnt+=check[sum-goal];
        }
        check[sum]++;
       }
       return cnt;
    }
};