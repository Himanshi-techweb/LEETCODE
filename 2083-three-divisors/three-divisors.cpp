class Solution {
public:
    bool isThree(int n) {
       int x=sqrt(n);
       unordered_set<int> st;
       for(int i=1;i<=x;i++){
         if(n%i==0){
           st.insert(i);
           int y=n/i;
           if(y<=n){
            st.insert(y);
           }
         }
       }
       cout<<st.size()<<endl;
       return st.size()==3; 
    }
};