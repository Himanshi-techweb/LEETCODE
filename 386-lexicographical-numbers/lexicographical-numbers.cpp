class Solution {
public:
    void f(int i,int n,vector<int> & check){
      if(i>n)return;
      check.push_back(i);
      for(int curr=0;curr<=9;curr++){
        int new_number=i*10 + curr;
        if(new_number>n)return ;
        f(new_number,n,check);
      }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> check;
        for(int i=1;i<=9;i++){
            f(i,n,check);
        }
        return check;
    }
};