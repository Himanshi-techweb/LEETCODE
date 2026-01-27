class Solution {
public:
    vector<int> extract(int n){
        vector<int> check;
        while(n>0){
            int re=n%10;
            check.push_back(re);
            n=n/10;
        }
        reverse(check.begin(),check.end());
        return check;
    }
    bool decrease(vector<int> arr){
        for(auto it=0;it+1<arr.size();it++){
            if(arr[it]<arr[it+1])return false;
        }
        return true;
    }
    vector<int> next_permutation(vector<int> &arr){
        //check first from back it is increasing
        int i=0;
        for(i=arr.size()-2;i>=0;i--){
           if(arr[i]<arr[i+1])break; 
        }
        //next greater element 
        int mini=INT_MAX;int ix=-1;
        for(int j=arr.size()-1;j>i;j--){
            if(arr[j]>arr[i]){
                ix=j;
                mini=arr[j];
                break;
            }
        }
        if(ix==-1)return {-1};
        swap(arr[i],arr[ix]);
        reverse(arr.begin()+i+1,arr.end());
        return arr;
    }
    int nextGreaterElement(int n) {
        vector<int> arr=extract(n);
        if(decrease(arr))return -1;
        vector<int> next=next_permutation(arr);
    //    reverse(next.begin(),next.end());
        int num = 0;
        for(int i = 0; i < next.size(); i++){
            int d = next[i];
            if(num > (INT_MAX - d) / 10) return -1;  // ✅ safe check
            num = num * 10 + d;
        }
return num;

    }
};