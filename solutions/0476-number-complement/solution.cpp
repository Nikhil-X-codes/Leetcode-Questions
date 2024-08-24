class Solution {
public:
    int findComplement(int num) {
        
        if(num == 1){
            return 0;
        }

        int len = (int) (log(num)/log(2)) + 1;
        unsigned int mask = (1U << len) - 1;
        return mask ^ num;
    }
};

