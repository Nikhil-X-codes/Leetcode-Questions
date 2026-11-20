
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        int water = 0;
        int left = 0, right = n - 1;
        int leftmax = height[0];
        int rightmax = height[n-1];

        while (left < right) {

            if (height[left] <= height[right]) {
                leftmax = max(leftmax, height[left]);
                water += leftmax - height[left];
                left++;
            }
            else {
                rightmax = max(rightmax, height[right]);
                water += rightmax - height[right];
                right--;
            }
        }

        return water;
    }
};

