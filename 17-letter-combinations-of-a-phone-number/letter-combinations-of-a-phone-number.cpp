class Solution {
public:
    void solve(int index,string &digits,vector<string> &result,string &combination,unordered_map<int,vector<char>> &check){
        if(index==digits.size()){
            result.push_back(combination);
            return;
        }
        int digit=digits[index]-'0';
        for(char c: check[digit]){
            combination.push_back(c);
            solve(index+1,digits,result,combination,check);
            combination.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
       unordered_map<int,vector<char>> check;
       check.insert({2,{'a','b','c'}}); 
       check.insert({3,{'d','e','f'}}); 
       check.insert({4,{'g','h','i'}}); 
       check.insert({5,{'j','k','l'}}); 
       check.insert({6,{'m','n','o'}}); 
       check.insert({7,{'p','q','r','s'}}); 
       check.insert({8,{'t','u','v'}}); 
       check.insert({9,{'w','x','y','z'}}); 
       string combination;
       vector<string> result;
       solve(0,digits,result,combination,check);
       return result;
    }
    
};