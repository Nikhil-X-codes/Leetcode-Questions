class Solution {
public:
     
    bool possible(int n, vector<int>& batteries, long long mid) {
        long long sum = 0;

        for (long long b : batteries) {
            sum += min(b, mid);
            if(sum >= (long long)n * mid) return true;
        }

        return false; 
    }

    long long maxRunTime(int n, vector<int>& batteries) {
        
        long long sum = 0;
        for (long long b : batteries) sum += b;

        long long left = 0;
        long long right = sum / n;
        long long res = 0;

        while (left <= right) {
            long long mid = left + (right - left) / 2;

            if (possible(n, batteries, mid)) {
                res = mid;       
                left = mid + 1;  
            } else {
                right = mid - 1; 
            }
        }

        return res;
    }
};

