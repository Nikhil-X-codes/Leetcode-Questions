class Solution {
public:
    bool checkDivisibility(int n) {
        
        long long sum = 0;
        long long prod = 1;
        int original = n;
        
        while(n){
            int rem = n % 10;
            sum += rem;
            prod *= rem;
            n /= 10;
        }
        
        return original % (sum + prod) == 0;
    }
};
