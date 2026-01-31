class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int ascii1=target;
        for(int i=0;i<letters.size();i++){
            int ascii2=letters[i];
            if(ascii2>ascii1)return ascii2;
        }
        return letters[0];
    }
};