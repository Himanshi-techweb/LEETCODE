class Solution {
public:
    string reorganizeString(string s) {
        // priority_queue<pair<int,char>,vector<pair<int,char>>,greater<pair<int,char>>>q;
        priority_queue<pair<int,char>>q;
        priority_queue<pair<int,char>>r;
        string ans="";
        vector<int> freq(26,0);
        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']++;
        }
        for(int i=0;i<freq.size();i++){
            if(freq[i]!=0)q.push({freq[i],i+'a'});
        }
        
        for(int i=0;i<s.size();i++){
            while(!q.empty() && q.top().first!=freq[q.top().second-'a'])q.pop();
            while(!q.empty() && ans.size()>0 && ans.back()==q.top().second){
                r.push(q.top());
                q.pop();
            }
            if(ans.size() ==0 || ans.back()!=q.top().second){
                ans+=(q.top().second);

                freq[q.top().second-'a']--;
                if(freq[q.top().second-'a']>0){
                    q.push({freq[q.top().second-'a'],q.top().second});
                }
                q.pop();
            }

            while(!r.empty()){
                q.push(r.top());r.pop();
            }
            
        }
        cout<<ans<<endl;
        return ans.size()!=s.size()?"":ans;



    }
};