class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int ans=0;
        for(int i=0;i<arr.size();i++){
            int x=arr[i];
            for(int j=i+1;j<arr.size();j++){
                int y=arr[j];
                for(int k=j+1;k<arr.size();k++){
                    int z=arr[k];
                    if(abs(arr[i] - arr[j]) <= a && abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};