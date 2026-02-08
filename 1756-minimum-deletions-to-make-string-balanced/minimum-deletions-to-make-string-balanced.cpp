class Solution {
public:
    int minimumDeletions(string s) {
        int size=s.size();
        

        vector<int> a_count(size);
        vector<int> b_count(size);
        int count_b=0;int count_a=0;
        for(int i=0;i<size;i++){
           b_count[i]=count_b;
           if(s[i]=='b')count_b++;
        }

        for(int i=size-1;i>=0;i--){
           a_count[i]=count_a;
           if(s[i]=='a')count_a++;
        }



        int ans=INT_MAX;
        for(int i=0;i<size;i++){
            ans=min(ans,a_count[i]+b_count[i]);
        }
        return ans;
    }
};