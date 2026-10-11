
class Solution {
public:
    bool isprime(int num) {
        
        if (num < 2) return false;

        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                return false;
            }
        }

        return true;
    }

    vector<int> maxPrimes(int n, int s) {
        vector<int> res;

        int sum = 0;

        for (int i = 2; i <= n; i++) {
            if (isprime(i)) {
                if (sum + i <= s) {
                    res.push_back(i);
                    sum += i;
                } else {
                    break;
                }
            }
        }

        return res;
    }
};

