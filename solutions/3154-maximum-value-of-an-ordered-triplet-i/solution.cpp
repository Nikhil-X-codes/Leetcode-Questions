class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;

        vector<int> v1(n, 0);
        vector<int> v2(n, 0);

        for (int i = 1; i < n; i++) {
            v1[i] = max(v1[i - 1], nums[i - 1]);
        }

        for (int i = n - 2; i >= 0; i--) {
            v2[i] = max(v2[i + 1], nums[i + 1]);
        }

        long long res = 0; 

       
        for (int j = 1; j < n - 1; j++) { 
            res = max(res, (long long)(v1[j] - nums[j]) * v2[j]);
        }

        return res;
    }
};

