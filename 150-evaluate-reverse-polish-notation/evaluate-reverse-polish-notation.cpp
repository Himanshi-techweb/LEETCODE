class Solution {
public:
    int evalRPN(vector<string>& arr) {
       stack<int> st;
       for(int i=0;i<arr.size();i++){
        if(isdigit(arr[i][0]) || isdigit(arr[i][1]))st.push(stoi(arr[i]));
        else{
            int a,b;
            if(st.size()>1){
                a=st.top();st.pop();
                b=st.top();st.pop();
            }
            if(arr[i]=="+"){
              int c=b+a;st.push(c);
            }
            else if(arr[i]=="-"){
              int c=b-a;st.push(c);
            }
            else if(arr[i]=="/" && a!=0){
              int c=b/a;st.push(c);
            }
            else{
               int c=b*a;st.push(c); 
            }
        }
       }
       return st.top(); 
    }
};