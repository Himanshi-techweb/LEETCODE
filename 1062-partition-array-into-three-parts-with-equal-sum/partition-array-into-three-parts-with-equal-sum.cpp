class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int total=accumulate(arr.begin(),arr.end(),0);
        if(total%3!=0)return false;
        else{
            int check=total/3;
            int sum=0;int i=0;bool op1=false;bool op2=false;bool op3=false;
            for(;i<arr.size();i++){
                sum+=arr[i];
                if(sum==check){
                    op1=true;
                    break;
                }
            }if(i<arr.size())i++;sum=0;
            for(;i<arr.size();i++){
                sum+=arr[i];
                if(sum==check){
                    op2=true;
                    break;
                }
            }if(i<arr.size())i++;sum=0;
            for(;i<arr.size();i++){
                sum+=arr[i];
                if(sum==check){
                    op3=true;
                    break;
                }
            }
            return op1&&op2&&op3;
        }
    }
};