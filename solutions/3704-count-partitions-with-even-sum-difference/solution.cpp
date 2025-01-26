class Solution {
public:
    int countPartitions(vector<int>& nums) {
        
        int n=nums.size();
        int count=0;
        int totalsum=0;

        for(int i:nums){
            totalsum+=i;
        }

        int leftsum=0;
        
        for(int i=0;i<=n-2;i++){
            leftsum+=nums[i];

             int rightsum = totalsum - leftsum;

            if((leftsum - rightsum) % 2 == 0){
                count++;
            }
        }

        return count;
    }
};
