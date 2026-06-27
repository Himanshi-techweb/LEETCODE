class Solution {
public:
    vector<int> res;int n;
    int k;
    unordered_map<string,int> flag;
    void solve(int i,vector<int> &arr,vector<int> &temp,int mask,vector<vector<string>> &people){
        if(i>=n){
            if((res.size()==0 || res.size()>temp.size()) && mask==k){
                res=temp;
            }
            return;
        }
       
        if(res.size()>0 && res.size()<temp.size())return;
        string key=to_string(i)+"_"+to_string(mask);
        if(flag.find(key)!=flag.end()){
            if(flag[key]<=temp.size())return ;
        }
        //skip 
        solve(i+1,arr,temp,mask,people);

        //take
        if(people[i].size()>0 ){
            temp.push_back(i);
            solve(i+1,arr,temp,mask|arr[i],people);
            temp.pop_back();
            flag[key]=(temp.size()!=0)?temp.size():-1;
        }

    }
    vector<int> smallestSufficientTeam(vector<string>& req, vector<vector<string>>& people) {
        unordered_map<string,int> st;
        int cnt=0;
        n=people.size();  
        k=(1<<req.size())-1;
        
        for(int i=0;i<req.size();i++){
            string str=req[i];
            st[str]=cnt++;
        }
        
        //create arr of mask  skill 
       
        vector<int> arr(n,0);
        for(int i=0;i<people.size();i++){
            for(auto it:people[i]){
                arr[i]=arr[i] | (1<<st[it]);
            }
        }
        vector<int> temp;
        solve(0,arr,temp,0,people);
        return res;
    }
};