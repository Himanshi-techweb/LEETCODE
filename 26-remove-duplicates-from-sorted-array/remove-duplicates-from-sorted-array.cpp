class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int i=0;
        int j=1;
        while(i<arr.size() && j<arr.size()){
           if(arr[i]==arr[j]){
            arr.erase(arr.begin()+j);
            
           }
           else{
            i++;
            j++;
           }
        }
        return arr.size();
       } 
};