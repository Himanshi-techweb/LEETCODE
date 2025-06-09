class Solution {
public:
    double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2) {
       int m=arr1.size();
       int n=arr2.size();
       int x=m+n;
       int ix1=(x/2);int ix2=(x/2)-1;//for odd index ignore ix1 and for even (x1+x2)/2
       int i=0;int j=0;int cnt=-1;int ix1_num=0;int ix2_num=0;
       while(i<m && j<n){
          if(arr1[i]<arr2[j]){
            cnt++;
            if(cnt==ix1)ix1_num=arr1[i];
            else if(cnt==ix2)ix2_num=arr1[i];
            i++;
          }
          else{
            cnt++;
            if(cnt==ix1)ix1_num=arr2[j];
            else if(cnt==ix2)ix2_num=arr2[j];
            j++;
          }
       }
       while(i<m){
        cnt++;
        if(cnt==ix1)ix1_num=arr1[i];
        else if(cnt==ix2)ix2_num=arr1[i];
        i++;
       }
       while(j<n){
        cnt++;
        if(cnt==ix1)ix1_num=arr2[j];
        else if(cnt==ix2)ix2_num=arr2[j];
        j++;
       }
       if(x%2==0)return (double)(ix1_num+ix2_num)/2;
       else return ix1_num; 
    }
};