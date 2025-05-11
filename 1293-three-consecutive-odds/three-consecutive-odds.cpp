class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int cnt=0;
        if(arr.size()<3)return false;
      for(int i=0;i<arr.size()-2;i++){
        cnt=0;
        for(int j=i;j<3+i;j++){
            if(arr[j]%2!=0)cnt++;
        }
         if(cnt>=3)return true;
      }
      return false;  
    }
};