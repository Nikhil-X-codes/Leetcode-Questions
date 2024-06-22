class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmostk(nums, k) - atmostk(nums, k-1);
    }

private:
    int atmostk(vector<int>& nums, int k){
        int st = 0;
        int ans = 0;
        int count = 0;
        for (int end = 0; end < nums.size(); end++) {
            if (nums[end] % 2 == 1) {
                count++;
            }
            while (st <= end && count > k) {
                if (nums[st++] % 2 == 1) {
                    count--;
                }
            }
            ans += (end - st + 1);
        }
        return ans;
    }
};

