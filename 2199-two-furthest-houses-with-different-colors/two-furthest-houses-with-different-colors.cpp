class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int maxi=INT_MIN;
        for(int i=0;i<colors.size();i++){
            for(int j=0;j<colors.size();j++){
                if(i==j || colors[i]==colors[j])continue;
                maxi=max(maxi,abs(i-j));
            }
        }
        return maxi;
    }
};