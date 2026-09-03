class Solution {
public:
    bool uniformArray(vector<int>& nums1) {

        int miniodd = INT_MAX;
        int n = nums1.size();

        for (int i = 0; i < n; i++) {
            if (nums1[i] % 2 == 1) {
                miniodd = min(miniodd, nums1[i]);
            }
        }
        
        if (miniodd == INT_MAX)
            return true;
            
        for (int x : nums1) {
            if (x % 2 == 0 && x < miniodd)
                return false;
        }

        return true;
    }
};
