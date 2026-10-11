
class Solution {
public:
    vector<int> maxProductPair(vector<int>& nums, int target) {
        
        int n = nums.size();
        vector<int> res = {-1, -1};
        int maxProduct = INT_MIN;

        for (int i = 0; i < n; i++) {
            
            for (int j = 0; j < n; j++) {
                
                if (i != j &&
                    nums[i] + nums[j] == target &&
                    nums[i] > nums[j]) {

                    int product = nums[i] * nums[j];

                    if (product > maxProduct) {
                        maxProduct = product;
                        res = {i, j};
                    }
                }
                
            }
            
        }

        return res;
    }
};

