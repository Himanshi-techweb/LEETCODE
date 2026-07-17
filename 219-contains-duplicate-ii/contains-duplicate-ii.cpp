class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,vector<int>> q;
        for(auto i=0;i<nums.size();i++){
            q[nums[i]].push_back(i);
        }

        for(auto it:q){    
            vector<int> arr=it.second;
            if(arr.size()==1 || (arr.size()==2 && abs(arr[1]-arr[0])>k))continue;
            int i=0;
            while(i<arr.size()-1){
                if(abs(arr[i]-arr[i+1])<=k)return true;
                i++;
            }

        }
        return false;
    }
};