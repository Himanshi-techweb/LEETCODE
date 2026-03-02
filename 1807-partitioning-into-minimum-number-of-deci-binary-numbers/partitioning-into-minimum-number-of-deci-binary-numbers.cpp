class Solution {
public:
    int minPartitions(string n) {
        int maxi=INT_MIN;
        for (int i=0;i<n.size();i++){
            if(n[i]-'0'>maxi)maxi=n[i]-'0';
        }
        return maxi;
    }
};