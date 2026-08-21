class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> st;
        for(int i=0;i<nums2.size();i++){
            st[nums2[i]]=i;
        }
        vector<int> ans;
        for(int i=0;i<nums1.size();i++){
            int x=nums1[i];
            int j=st[x];
            for(int k=j+1;k<nums2.size();k++){
                if(nums2[k]>x){
                    x=nums2[k];
                    break;
                }
            }
            if(nums1[i]!=x)ans.push_back(x);
            else ans.push_back(-1);
        }
        return ans;
    }
};