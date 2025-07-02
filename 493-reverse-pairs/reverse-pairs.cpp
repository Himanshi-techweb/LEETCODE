class Solution {
public:
    int merge(int low,int mid,int high,vector<int> &arr){
        vector<int> a(arr.begin()+low,arr.begin()+mid+1);
        vector<int> b(arr.begin()+mid+1,arr.begin()+high+1);
        int i=0;int j=0;
        int cnt=0;
        // vector<int> ans;
        int k=low;
        int l=low;int r=mid+1;
        while(l<mid+1){
           while(r<high+1 && arr[l]>(long long )2*arr[r]){
                r++;
           }l++;
           cnt+=(r-mid-1);
        }
        while(i<a.size() && j<b.size()){
            if(a[i]<=b[j]){
                arr[k++]=(a[i]);
                i++;
            }
            else{
              arr[k++]=(b[j]);
              j++;
            }
        }
        while(i<a.size()){
            arr[k++]=(a[i]);i++;
        }
        while(j<b.size()){
            arr[k++]=(b[j]);j++;
        }
        return cnt;
    }
    int mergesort(int low,int high,vector<int> &arr){
        int cnt=0;
        if(low>=high)return cnt;
        int mid=low+(high-low)/2;
        cnt+=mergesort(low,mid,arr);
        cnt+=mergesort(mid+1,high,arr);
        cnt+=merge(low,mid,high,arr);
        return cnt;
    }
    // Function to count inversions in the array.
    int reversePairs(vector<int> &arr) {
        // Your Code Here
        return mergesort(0,arr.size()-1,arr);
    }
};