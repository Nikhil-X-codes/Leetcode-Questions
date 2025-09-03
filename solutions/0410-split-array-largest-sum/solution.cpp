
class Solution {
public:
    bool possible(vector<int>& nums, int k, int mid) {
        int pagesum = 0;
        int students = 1;

        for (int i = 0; i < nums.size(); i++) {

            if (pagesum + nums[i] <= mid) {
                pagesum += nums[i];
            }
            
             else {
                students++;
                pagesum = nums[i];
                if (students > k ) return false;
            }
        }
        return true;
    }

    int splitArray(vector<int>& nums, int k) {

        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }

        int st = *max_element(nums.begin(), nums.end());
        int end = sum;
        int ans = -1;

        while (st <= end) {

            int mid = st + (end - st) / 2;

            if (possible(nums, k, mid)) {
                ans = mid;
                end = mid - 1;
            }
            
             else {
                st = mid + 1;
            }
        }

        return ans;
    }
};



