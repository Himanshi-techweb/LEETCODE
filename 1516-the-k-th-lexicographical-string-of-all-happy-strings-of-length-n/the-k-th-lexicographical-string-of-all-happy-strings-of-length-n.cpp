class Solution {
public:
    vector<char> l={'a','b','c'};
    string ans="";
    void check(int &count,int k,string &x,int n){
        if(x.size()==n){
           count++;
           if(count==k){
            ans=x;
           }
           return; 
        }
        for(int i=0;i<l.size();i++){
            //start
            if(x.size()==0){
               x.push_back(l[i]);
               check(count,k,x,n);
               x.pop_back();
            }
            //already contain some letter in 
            else{
               //check if back element is not same as current character
               char back=x.back();
               if(l[i]==back)continue;
               else{
                   x.push_back(l[i]);
                   check(count,k,x,n);
                   x.pop_back();
               }
            }
            cout<<x<<endl;

        }
    }
    string getHappyString(int n, int k) {
         string x="";
        // int count=0;
        // check(count,k,x,n);
        // return ans;



        for(int i=0;i<n;i++){
            for(char ch:l){
                if(!x.empty() && x.back()==ch)continue;
                int j=n-i-1;
                int cnt=1<<j;
                if(k>cnt)k-=cnt;
                else{
                    x.push_back(ch);
                    break;
                }
            }
        }
        if(x.size()!=n)return "";
        return x;
    }
};