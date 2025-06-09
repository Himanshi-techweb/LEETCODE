class Solution {
public:
    // double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2) {
    //    int m=arr1.size();
    //    int n=arr2.size();
    //    int x=m+n;
    //    int ix1=(x/2);int ix2=(x/2)-1;//for odd index ignore ix1 and for even (x1+x2)/2
    //    int i=0;int j=0;int cnt=-1;int ix1_num=0;int ix2_num=0;
    //    while(i<m && j<n){
    //       if(arr1[i]<arr2[j]){
    //         cnt++;
    //         if(cnt==ix1)ix1_num=arr1[i];
    //         else if(cnt==ix2)ix2_num=arr1[i];
    //         i++;
    //       }
    //       else{
    //         cnt++;
    //         if(cnt==ix1)ix1_num=arr2[j];
    //         else if(cnt==ix2)ix2_num=arr2[j];
    //         j++;
    //       }
    //    }
    //    while(i<m){
    //     cnt++;
    //     if(cnt==ix1)ix1_num=arr1[i];
    //     else if(cnt==ix2)ix2_num=arr1[i];
    //     i++;
    //    }
    //    while(j<n){
    //     cnt++;
    //     if(cnt==ix1)ix1_num=arr2[j];
    //     else if(cnt==ix2)ix2_num=arr2[j];
    //     j++;
    //    }
    //    if(x%2==0)return (double)(ix1_num+ix2_num)/2;
    //    else return ix1_num; 
    // }
     double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2) {
        int n1=arr1.size();int n2=arr2.size();int n=(n1+n2);
        if(n1>n2)return findMedianSortedArrays(arr2,arr1);
        int low=0;int high=n1;int left=(n+1)/2;
        while(low<=high){
            int mid1=(low+high)>>1;
            int mid2=left-mid1;
            int l1=INT_MIN;int l2=INT_MIN;
            int r1=INT_MAX;int r2=INT_MAX;
            if(mid1<n1)r1=arr1[mid1];
            if(mid2<n2)r2=arr2[mid2];
            if(mid1-1>=0)l1=arr1[mid1-1];
            if(mid2-1>=0)l2=arr2[mid2-1];
            if(l1<=r2 && l2<=r1){
                if(n%2!=0)return max(l1,l2);
                else{
                    return ((double)((max(l1,l2)+min(r1,r2))/2.0));
                }
            }
            else if(l1>r2)high=mid1-1;
            else low=mid1+1;
        }
        return 0;
     }
};