class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
     set<string> q;
     for(int i=0;i<words.size();i++){
        string str1=words[i];
        for(int j=0;j<words.size();j++){
            if(j==i)continue;
            string str2=words[j];
            if(str1.size()<=str2.size()){
                if(str2.find(str1)!=string::npos){
                    q.insert(str1);
                }
            }
            else{
                if(str1.find(str2)!=string::npos){
                    q.insert(str2);
                }
            }
        }
     }vector<string> ans;
     for(auto x:q){
         ans.push_back(x);
     } return ans; 
    }
};