class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int n=arr.size();
        //left 
        if(arr.size()==1 || arr[0]!=arr[1])return arr[0];
        if(arr[n-1]!=arr[n-2])return arr[n-1];
        int l=1;int h=n-2;
        while(l<=h){
            int mid=(l+h)/2;
            if(arr[mid]!=arr[mid-1] && arr[mid]!=arr[mid+1])return arr[mid];
            else if(mid%2==0){
                if(arr[mid-1]==arr[mid])h--;
                else l++;
            }
            else if(mid%2!=0){
                if(arr[mid-1]==arr[mid])l++;
                else h--;
            }
        }
        return 0;

    }
};