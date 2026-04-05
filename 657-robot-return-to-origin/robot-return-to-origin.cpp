class Solution {
public:
    // unordered_map<pair<char,pair<int,int>>> str;
    // str['R']={0,1};
    // str['L']={0,-1};
    // str['U']={-1,0};
    // str['D']={1,0};
    bool judgeCircle(string moves) {
       int i=0;int j=0;
       int k=0;
        while(k<moves.size()){
            if(moves[k]=='R')j++;
            else if(moves[k]=='L')j--;
            else if(moves[k]=='D')i++;
            else i--;
            k++;
            // if(i==0 && j==0)return true;
        }
        if(i==0 && j==0)return true;
        return false;

    }
};