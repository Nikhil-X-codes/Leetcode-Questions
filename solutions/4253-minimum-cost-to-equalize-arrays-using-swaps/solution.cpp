class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size();
        int count = 0;

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        if (nums1 == nums2)
            return 0;

        unordered_map<int, int> mp1, mp2, mp3;

        for (int i : nums1) {
            mp1[i]++;
            mp3[i]++;
        }

        for (int i : nums2) {
            mp2[i]++;
            mp3[i]++;
        }

        for (auto& [u, v] : mp3) {
            if (v % 2 != 0)
                return -1;

            int val1 = mp1[u];
            int val2 = mp2[u];
            count += abs(val1 - val2);
        }

        return count / 4;
    }
};
