class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if (nums.empty()) return 0;

        unordered_set<int> s(nums.begin(), nums.end());
        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (s.find(nums[i] - 1) != s.end()) {
                continue;
            } else {
                int count = 0;
                int current = nums[i];

                while (s.find(current) != s.end()) {
                    count++;
                    current++;
                }
                ans = max(ans, count); 
            }
        }

        return ans;
    }
};

