class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int curr=arr[0];int k=1;
      for(int i=1;i<arr.size();){
        if(arr[i]==curr){
            arr.erase(arr.begin()+i);
        }
        else{
            curr=arr[i];k++;
            i++;
        }
      } 
      return k; 
    }
};