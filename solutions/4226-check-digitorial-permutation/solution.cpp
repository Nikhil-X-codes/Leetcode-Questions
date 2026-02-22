class Solution {
public:
    bool isDigitorialPermutation(int n) {

     int fact[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880}; 

        vector<int> originalCounts(10, 0);
        long long digitorialSum = 0;
        int temp = n;

        while(temp > 0){
            int digit = temp % 10;
            originalCounts[digit]++;
            digitorialSum += fact[digit];
            temp /= 10;
        }

        vector<int> sumCounts(10, 0);
        long long checkSum = digitorialSum;

        while (checkSum > 0) {
            sumCounts[checkSum % 10]++;
            checkSum /= 10;
        }

        for (int i = 0; i < 10; i++) {
            if (originalCounts[i] != sumCounts[i]) {
                return false;
            }
        }

        return true;
    }
};
