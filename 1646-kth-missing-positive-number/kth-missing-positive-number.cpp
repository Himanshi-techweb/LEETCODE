class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int right=1;
        int l=0;int h=arr.size()-1;
        while(l<=h){
            int mid=(l+h)/2;
            int actual=mid+1;
            int there=arr[mid];
            int diff=there-actual;
            if(diff<k)l=mid+1;
            else {
                right=mid;
                h=mid-1;
            }
        }
        return l+k;
        

    }
};