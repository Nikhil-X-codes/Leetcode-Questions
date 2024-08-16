class Solution {
public:
    int smallestDistancePair(std::vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());  // Sort the array
        
        std::vector<int> distances;
        
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                distances.push_back(nums[j] - nums[i]);  // Calculate the distance between pairs
            }
        }

        // Use nth_element to find the K-th smallest element in distances
        std::nth_element(distances.begin(), distances.begin() + k - 1, distances.end());
        
        return distances[k - 1];  // The K-th smallest element
    }
};
