class Solution {
public:
    long long putMarbles(vector<int>& weight, int k) {
        if(k==1)return 0;
        vector<long long> arr(weight.size()-1,0);
        arr[0]=weight[0];
        for(int i=0;i<weight.size()-1;i++){
            arr[i]=weight[i+1]+weight[i];
        }
        sort(arr.begin(),arr.end());
        long long mini=0;long long maxi=0;
        for(int i=0;i<k-1;i++){
            mini+=arr[i];
            maxi+=arr[arr.size()-i-1];
        }return abs(maxi-mini);
    }
};