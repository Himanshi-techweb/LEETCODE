class Solution {
public:
    int evalRPN(vector<string>& tokens) {
      stack<int> q;
    //   string temp=tokens[0];
      q.push(stoi(tokens[0]));
    //   if(temp!="+" && temp!="-" && temp!="/" && temp!="*"){
    //         int x=stoi(temp);
    //        q.push(x);
    //   }
      int i=1;
      while( i<tokens.size()){
        //  temp=tokens[i];
        if(tokens[i]!="+" && tokens[i]!="-" && tokens[i]!="/"  && tokens[i]!="*"){
           q.push(stoi(tokens[i]));
        }
        else{
           int check1=q.top();
           q.pop();
           int check2=q.top();
           q.pop();
           if(tokens[i]=="+"){
            q.push(check1+check2);
           }
           if(tokens[i]=="-"){
            q.push(check2-check1);
           }
           if(tokens[i]=="*"){
            q.push(check1*check2);
           }
           if(tokens[i]=="/"){
            // if(check1!=0){
              q.push(check2/check1);
            // }  
           }
        }
        i++;
      }
      int ans=q.top();
      return ans;  
    }
};