class Solution {
public:
    int evalRPN(vector<string>& tokens) {
      stack<int> q;
      string temp=tokens[0];
      q.push(stoi(temp));
    //   if(temp!="+" && temp!="-" && temp!="/" && temp!="*"){
    //         int x=stoi(temp);
    //        q.push(x);
    //   }
      int i=1;
      while( i<tokens.size()){
         temp=tokens[i];
        if(temp!="+" && temp!="-" && temp!="/"  && temp!="*"){
           q.push(stoi(temp));
        }
        else{
           int check1=q.top();
           q.pop();
           int check2=q.top();
           q.pop();
           if(temp=="+"){
            q.push(check1+check2);
           }
           if(temp=="-"){
            q.push(check2-check1);
           }
           if(temp=="*"){
            q.push(check1*check2);
           }
           if(temp=="/"){
            if(check1!=0){
              q.push(check2/check1);
            }  
           }
        }
        i++;
      }
      long long ans=q.top();
      return ans;  
    }
};