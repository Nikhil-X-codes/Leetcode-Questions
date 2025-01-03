class Solution {
public:

    int waysToSplitArray(vector<int>& nums) {
        
        long long totalsum = 0; 
        int count = 0;
        long long currsum = 0;

        for(int i=0;i<nums.size();i++){
          totalsum+=nums[i];
        }
        
        for(int i=0;i<nums.size()-1;i++){
          currsum+=nums[i];

            if (currsum >= (totalsum - currsum)) {
                count++;
            }
        }

return count;
    }
};
