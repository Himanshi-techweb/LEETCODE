class Solution {
public:
    int reverseBits(int n) {
      uint32_t result=0;
      int i=0;
      while(i<32){
        result=result<<1;
        result= result | (n&1);
        n=n>>1;
        i++;
      }  
      return result;
    }
};