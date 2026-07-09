class Solution {
public:
    
    const int MOD=1e9 +7;
    int rangeSum(vector<int>& num, int n, int left, int right) {
        vector<int> arr;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                
                sum+=num[j];
                arr.push_back(sum);
            }
        }
        sort(arr.begin(),arr.end());
        for(auto it:arr)cout<<it<<" ";
        long long sum=0;
        for(int i=left-1;i<right;i++)sum=(sum+arr[i])%MOD;
        return sum;
    }
};