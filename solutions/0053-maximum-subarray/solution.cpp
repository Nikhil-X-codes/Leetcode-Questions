class Solution {
public:
    int maxSubArray(vector<int>& nums) {

int sum=0;
int maxisum=nums[0];

for(int i=0;i<nums.size();i++){
    sum+=nums[i];

    maxisum=max(sum,maxisum);

    if(sum < 0)
    sum=0;
}
return maxisum;
   }
};
