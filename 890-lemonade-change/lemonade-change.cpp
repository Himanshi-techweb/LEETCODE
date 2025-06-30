class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
      unordered_map<int,int> check;
      for(int i=0;i<bills.size();i++){
        if(bills[i]==10){
          if(check[5]>=1){
            check[5]--;
          }
          else{
            return false;
          }
        }
        else if(bills[i]==20){
            if(check[5]>=1 && check[10]>=1){
                check[5]--;check[10]--;
            }
            else if(check[5]>=3){
              check[5]--;check[5]--;check[5]--;
            }
            
            else{
                return false;
            }
        }
        check[bills[i]]++;
      }
      return true;   
    }
};