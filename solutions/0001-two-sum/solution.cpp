class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

vector<int> result;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i] + nums[j] == target ){
  result.push_back(i);
                result.push_back(j);
                }
            }
        }

// vector<int> result;
// sort(nums.begin(), nums.end());
// int left = 0;
// int right = nums.size() - 1;
// int n = nums.size();
// while (left < right) {
//     int sum = nums[left] + nums[right];
//     if (sum == target) {
//         result.push_back(left);
//         result.push_back(right);
//         break;
//     } else if (sum < target) {
//         left++;
//     } else {
//         right--; // Corrected this line to decrement right
//     }
// }

return result;
    }
};
