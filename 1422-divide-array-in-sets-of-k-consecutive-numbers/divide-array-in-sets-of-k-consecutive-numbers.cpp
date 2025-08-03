class Solution {
public:
    bool isPossibleDivide(vector<int>& arr, int k) {
       if(arr.size()%k!=0)return false;
       set<int> st;
       unordered_map<int,int> check;
       //maintain freq of each element and also ensure that it is there by set
       for(auto it:arr){
            st.insert(it);
            check[it]++;
       }
       while(true){
         auto it=st.begin();
         int next=*it;
         int size=0;
         while(size<k){
           if(check.find(next)!=check.end()){
            size++;
            check[next]--;
            if(check[next]==0){
                check.erase(next);
                auto it=st.find(next);
                if(it!=st.end())st.erase(it);
            }
            next=next+1;
           }
           else  return false;  
         }
         if(st.size()==0 || check.size()==0)break;
       }
       return true;
    }
};