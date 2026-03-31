class Solution {
public:
    string generateString(string str1, string str2) {
       string small;
       int n=str1.size();
       int m=str2.size();
       string result(n+m-1,'0');
       vector<bool>canchange(n+m-1,true);
       for(int i=0;i<str1.size();i++){
         if(str1[i]=='T'){
            int i_=i;
            for(int j=0;j<m;j++){
                if(result[i_]!='0' && result[i_]!=str2[j])return "";
                result[i_]=str2[j];
                
                canchange[i_]=false;
                i_++;
            }
            
         } 
       } 
       for(int i=0;i<n+m-1;i++){
        if(result[i]=='0')result[i]='a';
       }

       //check;
       for(int i=0;i<n;i++){
        if(str1[i]=='F'){
            //iterate from back and check if it canchange in between i to i+m then change it from back
            string str=result.substr(i,m);
            if(str!=str2)continue;
            int i_=i+m-1;
            while(i_>=i && canchange[i_]==false){
                i_--;
            }
            if(i_<i)return "";
            result[i_]='b';
        }
       }
       return result;
    }
};