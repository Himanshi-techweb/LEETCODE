class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size())return findMedianSortedArrays(nums2,nums1);
        int low=0;int high=nums1.size();
        
        int l1=-1;int l2=-1;int r1=-1;int r2=-1;
        int total=nums1.size()+nums2.size();
        int left=(total+1)/2;
        while(low<=high){
            int mid1=(low+high)/2;
            int mid2=left-mid1;
            l1=(mid1==0)?INT_MIN:nums1[mid1-1];
            l2=(mid2==0)?INT_MIN:nums2[mid2-1];
            r1=(mid1==nums1.size())?INT_MAX:nums1[mid1];
            r2=(mid2==nums2.size())?INT_MAX:nums2[mid2];
            if(l1<=r2 && l2<=r1){
                if(total%2==0){
                    return ((double)(max(l1,l2))+(min(r1,r2)))/2;
                }
                else return max(l1,l2);
            }
            else if(l1>r2){
                high=mid1-1;
            }
            else low=mid1+1;
        }
        return 0;
    }
};