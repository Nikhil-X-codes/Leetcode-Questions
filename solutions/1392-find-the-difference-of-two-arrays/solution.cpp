class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());
        
        vector<int> list1;
        vector<int> list2;
        
        for (int i : s1) {
            if (s2.find(i) == s2.end()) {
                list1.push_back(i);
            }
        }
        
        for (int i : s2) {
            if (s1.find(i) == s1.end()) {
                list2.push_back(i);
            }
        }
        
        return {list1, list2};
    }
};

