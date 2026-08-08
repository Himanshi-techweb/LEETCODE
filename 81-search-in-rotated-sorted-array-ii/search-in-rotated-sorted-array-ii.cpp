class Solution {
public:
    bool search(vector<int>& arr, int t) {
        //may be left part sort or right part or both can 
        int l=0;int h=arr.size()-1;
        while(l<=h){
            int m=(l+h)/2;
            //left sort
            if(arr[m]==t)return true;

            else if(arr[l]<=arr[m]){
                if(t>=arr[l] && t<=arr[m])h--;
                else l++;

            }
            //right sort
            else if(arr[m]<=arr[h]){
                if(t>=arr[m] && t<=arr[h])l++;
                else h--;

            }
        }
        return false;
    }
};