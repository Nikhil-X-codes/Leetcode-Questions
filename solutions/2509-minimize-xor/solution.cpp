class Solution {
public:
    int minimizeXor(int num1, int num2) {
        
      int count = __builtin_popcount(num2);

        bitset<32> bits(num1); 
        bitset<32> result;  

      for(int i=31;i>=0 and count > 0;i--){

       if(bits[i]){
        result.set(i); 
        count--;
       }

      }

      for(int i=0;i<32 and count > 0;i++){
       
       if(!result[i]){
        result.set(i); 
        count--;
       }

      }

return (int)result.to_ulong();
    }
};
