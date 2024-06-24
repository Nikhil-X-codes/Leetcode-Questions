class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 0;
        int flips = 0;
        vector<int> temp(n, 0);
        
        for (int i = 0; i < n; ++i) {
            if (i >= k) {
                flips ^= temp[i - k];
            }
            
            if (flips == nums[i]) {
                if (i + k > n) {
                    return -1;
                }
                temp[i] = 1;
                flips ^= 1;
                res++;
            }
        }
        
        return res;
    }
};

