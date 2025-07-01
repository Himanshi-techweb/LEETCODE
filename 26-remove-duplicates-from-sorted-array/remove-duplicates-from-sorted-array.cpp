class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
       int curr=1;int next=0;
       while(curr<arr.size()){
           if(arr[curr]==arr[next]){
            curr++;
           }
           else{
             if(next+1<arr.size()  && curr!=next){
                swap(arr[next+1],arr[curr]);
                next=next+1;
                
             }
             curr++;
           }
       }
       return next+1;
    }
};