#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int totalLength = m + n;
        vector<int> nums3(totalLength);
        
        int i = 0, j = 0, k = 0;

        // Merge two sorted arrays
        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                nums3[k++] = nums1[i++];
            } else {
                nums3[k++] = nums2[j++];
            }
        }

        // Copy any remaining elements from nums1
        while (i < m) {
            nums3[k++] = nums1[i++];
        }

        // Copy any remaining elements from nums2
        while (j < n) {
            nums3[k++] = nums2[j++];
        }

        // Calculate the median
        if (totalLength % 2 == 1) {
            return nums3[totalLength / 2];
        } else {
            return (nums3[totalLength / 2 - 1] + nums3[totalLength / 2]) / 2.0;
        }
    }
};

