class Solution {
public:
    typedef long long ll;
    const ll MAX=1e15;
    int n ;
    // ll solve(vector<int> &arr,int k,int dist,int second_subarray_startindex,int curr,int subarray_count,vector<vector<vector<ll>>>&dp){
    //       //if dist is greater then dont take it return 
    //       //if k is greater then dont take it return
    //       //no constraint on second subarray can take anything so start from each index and take it then after from it 
    //       //if dist is equal or less than with second_subarray_startindexious take it 
    //       //either include it if including then mention index of it 
    //       //not including then mention second_subarray_startindexious index only
    //       if(subarray_count>k)return MAX;
    //       if(curr==n)return (subarray_count==k)?0:MAX;
    //       if(dp[curr][second_subarray_startindex][subarray_count]!=-1)return dp[curr][second_subarray_startindex][subarray_count];
    //         ll mini=MAX;
    //         if(curr-second_subarray_startindex<=dist){
    //             ll include=solve(arr,k,dist,second_subarray_startindex,curr+1,subarray_count+1,dp);
    //             if(include!=MAX)mini=min(mini,include+arr[curr]);
    //         }
    //         ll exclude=solve(arr,k,dist,second_subarray_startindex,curr+1,subarray_count,dp);
    //         if(exclude!=MAX)mini=min(mini,exclude);
    //         return dp[curr][second_subarray_startindex][subarray_count]=mini;

    // }
    long long minimumCost(vector<int>& nums, int k, int dist) {
        --k;
        multiset<int> l(nums.begin() + 1, nums.begin() + dist + 2), r;
        long long s = accumulate(nums.begin(), nums.begin() + dist + 2, 0LL);
        while (l.size() > k) {
            int x = *l.rbegin();
            l.erase(l.find(x));
            s -= x;
            r.insert(x);
        }
        long long ans = s;
        for (int i = dist + 2; i < nums.size(); ++i) {
            int x = nums[i - dist - 1];
            auto it = l.find(x);
            if (it != l.end()) {
                l.erase(it);
                s -= x;
            } else {
                r.erase(r.find(x));
            }
            int y = nums[i];
            if (y < *l.rbegin()) {
                l.insert(y);
                s += y;
            } else {
                r.insert(y);
            }
            while (l.size() == k - 1) {
                int x = *r.begin();
                r.erase(r.find(x));
                l.insert(x);
                s += x;
            }
            while (l.size() == k + 1) {
                int x = *l.rbegin();
                l.erase(l.find(x));
                s -= x;
                r.insert(x);
            }
            ans = min(ans, s);
        }
        return ans;
    }



};