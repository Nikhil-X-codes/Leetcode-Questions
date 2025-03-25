
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0, right = 0;
        int zerocount = 0;  
        int maxlen = 0;      

        while (right < nums.size()) {
            if (nums[right] == 0) {
                zerocount++;
            }

            while (zerocount > 1) {
                if (nums[left] == 0) {
                    zerocount--;
                }
                left++;
            }

            maxlen = max(maxlen, right - left + 1);

            right++;
        }

        return maxlen - 1;
    }
};

