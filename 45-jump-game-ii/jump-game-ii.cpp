class Solution {
public:
    int jump(vector<int>& arr) {
       int l=0;int r=0;int jump=0;
       while( l<=r && r<arr.size()-1){
          //maximum in range of l and r with index;
          r=l+arr[l];
          jump++;
          if(r>=arr.size()-1)break;
          int maxi=arr[l]+l;int ix=0;
          for(int k=l+1;k<=r;k++){
            if(arr[k]+k>=maxi){
              maxi=arr[k]+k;ix=k;
            } 
          }
          l=ix;
       } 
       return jump;
    }
};