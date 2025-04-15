class Solution {
public:
    // vector<int> majorityElement(vector<int>& arr) {
    //    unordered_map<int,int> check;int n=arr.size();
    //    vector<int> ans;
    //    for(auto x:arr){
    //       check[x]++;
    //    }
    //    for(auto x:check){
    //     if(x.second>n/3){
    //         ans.push_back(x.first);
    //     }
    //    }
    //    return ans; 
    // }


    vector<int> majorityElement(vector<int>& arr) {
       int count1=0;int count2=0;
       int ele1=0;int ele2=0;
       for(auto x:arr){
        if(count1==0 &&  x!=ele2){
            count1=1;
            ele1=x;
        }
        else if(count2==0 &&  x!=ele1){
            count2=1;
            ele2=x;
        }
        else if(x==ele1){
            count1++;
        }
        else if(x==ele2){
            count2++;
        }
        else{
            count1--;count2--;
        }
       }
       count1=0;count2=0;
       for(auto x: arr){
        if(ele1==x)count1++;
        if(ele2==x)count2++;
       }
       int check=(int)arr.size()/3  + 1;vector<int> ans;
       if(count1>=check)ans.push_back(ele1);
       if(ele1 !=ele2 && count2>=check)ans.push_back(ele2);
       return ans;
    }
};