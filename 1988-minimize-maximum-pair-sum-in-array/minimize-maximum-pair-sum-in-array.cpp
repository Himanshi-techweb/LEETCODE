#include <queue>
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int i=nums.size()-1;
         int maxi=INT_MIN;int mini=INT_MIN;
        int ans=0;
        priority_queue<vector<int>> max_heap;
        // priority_queue<<vector<int>,vector<vector<int>>,greater<vector<vector<int>>>> min_heap;
        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > min_heap;

        for(auto i=0;i<nums.size();i++){
            max_heap.push({nums[i],i});
            min_heap.push({nums[i],i});
        }
        while(i>1){
            maxi=(max_heap.top())[0];
            mini=(min_heap.top())[0];
            ans=max(ans,maxi+mini);
            max_heap.pop();min_heap.pop();
            i--;i--;
        }
        ans=max(ans,max_heap.top()[0]+min_heap.top()[0]);
        return ans;

    }
};