class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        //int n=recipes.size();
    //   map<string,int> check;
    //   for(auto x:supplies){
    //     check.insert({x,1});
    //   }vector<string> ans;
    //   for(int i=0;i<n;i++){
    //     string recipe=recipes[i];
    //     vector<string> ingre=ingredients[i];
    //     bool make=true; 
    //     for(auto x:ingre){
    //         if(check.find(x)==check.end()){
    //              make=false;
    //         }
    //     }
    //     if(make){
    //         check.insert({recipe,1});
    //         ans.push_back(recipe);
    //     }
    //   } 
    //   return ans; 
    //=----------------------not work due toc ycle dependency then make it using topological sorting algorithm (kahn's algorithm)




    map<string,vector<string>> check;
    map<string,int> in;
    unordered_set<string> supply;
    for(auto x:supplies){
        supply.insert(x);
    }
    for(auto x: recipes){
        in[x]=0;
    }
    for(int i=0;i<recipes.size();i++){
        string recipe=recipes[i];
        vector<string> ingre=ingredients[i];
        for(auto x:ingre){
            if(supply.find(x)==supply.end()){
                check[x].push_back(recipe);
                in[recipe]++;
            }
        }
    }
    queue<string> q;
     for(auto x:in){
        if(x.second==0){
            q.push(x.first);
        }
     }vector<string> ans;
     while(!q.empty()){
        string str =q.front();
        q.pop();
        if(check.find(str)!=check.end()){
          vector<string> arr=check[str];
          for(auto x:arr){
            in[x]--;
            if(in[x]==0)q.push(x);
          }
        }
        ans.push_back(str);
     }return ans;
    }
};