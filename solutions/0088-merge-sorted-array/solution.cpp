class Solution {
public:
    void merge(vector<int>& nums1, int m,vector<int>& nums2, int n) {
       vector<int> merged;
       
        int i = 0, j = 0;
        
        // Use two pointers to traverse both arrays up to their respective limits
        while (i < m && j < n) {

            if (nums1[i] <= nums2[j]) {
                merged.push_back(nums1[i]);
                i++;
            } 
            
            else {
                merged.push_back(nums2[j]);
                j++;
            }
        }

        // Add remaining elements from nums1, if any
        while (i < m) {
            merged.push_back(nums1[i]);
            i++;
        }

        // Add remaining elements from nums2, if any
        while (j < n) {
            merged.push_back(nums2[j]);
            j++;
        }

        // Copy the merged result back into nums1
        for (int k = 0; k < merged.size(); k++) {
            nums1[k] = merged[k];
        }
    }
};

