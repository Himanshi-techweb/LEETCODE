class Solution {
public:
    int minOperations(vector<int>& arr) {
       int i=0;
       int n=arr.size();
       int k=0;
       while(i<n-2){
        if(arr[i]==0){
            for(int j=i;j<i+3;j++){
                arr[j]=(arr[j]==0)?1:0;
            }
            k++;
        }i++;
       } 
       if(arr[n-2]==0 || arr[n-1]==0)return -1;
       return k;
    }
};