class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int cols=encodedText.size()/rows;
        if(encodedText.size()==0)return "";
        vector<vector<char>> arr(rows,vector<char>(cols));
        int k=0;
        // for(int i=0;i<rows;i++){
        //     for(int j=0;j<cols;j++){
        //         arr[i][j]=encodedText[k++];
        //     }
        // }


        //traverse from 0,0 to row-1,col-1
        string str="";

        //start of each must be row 0 then increase row by 1 col by 1
        //
        for(int j=0;j<cols;j++){
            int i=0;int k=j;
            // if(j!=0 && arr[0][j]==' ')break;
            while(i<rows && k<cols){
                str.push_back(encodedText[(i*cols +k)]);
                i++;k++;
            }
        }
        int i=str.size()-1;
        while(str.back()==' '){
            str.pop_back();
        }
        // for(int k=0;k<i;k++)cout<<str[k];
        
        return str;
    }
};