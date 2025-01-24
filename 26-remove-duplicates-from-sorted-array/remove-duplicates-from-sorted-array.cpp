class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
    //     int i=0;
    //     int j=1;
    //     while(i<arr.size() && j<arr.size()){
    //        if(arr[i]==arr[j]){
    //         arr.erase(arr.begin()+j);
    //        }
    //        else{
    //         i++;
    //         j++;
    //        }
    //     }
    //     return arr.size();
    //    } 


    /////////////optimal
    int i=0;
    for(int j=1;j<arr.size();j++){
        if(arr[i]!=arr[j]){
            i++;
            arr[i]=arr[j];
        }
    }
    return i+1;}
};