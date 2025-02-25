class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        
        const int MOD = 1e9 + 7;
        int evencount = 1; 
        int oddcount = 0;
        int sum = 0;
        int result = 0;

        for (int num : arr) {
            sum += num;

            if (sum % 2 == 1) { 
                result += evencount;
                oddcount++;
            } else {  
                result += oddcount;
                evencount++;
            }

            result %= MOD;  
        }

        return result;
    }
};

