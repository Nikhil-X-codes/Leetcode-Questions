class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        
        int xor_sum = 0;

        for(int num:derived){
          xor_sum ^= num;
        }

        if(xor_sum == 0) return true;

        return false;
     
    }
};
