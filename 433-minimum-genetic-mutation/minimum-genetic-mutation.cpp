class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        queue<pair<string,int>> q;
        q.push({startGene,0});
        unordered_set<string> check;
        for(auto it:bank)check.insert(it);
        vector<char> rc={'A','C','G','T'};
        while(!q.empty()){
            auto str=q.front().first;auto freq=q.front().second;
            q.pop();
            if(str==endGene)return freq;
            for(int i=0;i<str.size();i++){
              char origi=str[i];
              for(auto it:rc){
                str[i]=it;
                if(check.find(str)!=check.end()){
                    q.push({str,freq+1});
                    check.erase(str);
                }
              } 
              str[i]=origi;
            }
        }
        return -1;
    }
};