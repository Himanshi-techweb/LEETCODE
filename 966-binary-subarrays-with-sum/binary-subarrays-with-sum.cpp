class Solution {
public:
    int solve(vector<int> &arr, int goal) {
    if(goal<0)return 0;
    int l = 0, ans = 0;
    long long sum = 0;
    for (int r = 0; r < arr.size(); r++) {
        sum += arr[r];
        while (sum > goal) {
            sum -= arr[l];
            l++;
        }
        ans += (r - l + 1);
    }
    return ans;
}

int numSubarraysWithSum(vector<int>& arr, int goal) {
    return solve(arr, goal) - solve(arr, goal - 1);
}

};