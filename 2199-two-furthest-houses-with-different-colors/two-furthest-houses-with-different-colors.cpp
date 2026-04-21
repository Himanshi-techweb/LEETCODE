class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int maxi=INT_MIN;
        int s=0;int e=colors.size()-1;
        while(s<colors.size() && colors[s]==colors[colors.size()-1])s++;
        while(e>=0 && colors[e]==colors[0]){
           e--; 
        }
        int x= max(e,(int)colors.size()-s-1);
        return x;
    }
};