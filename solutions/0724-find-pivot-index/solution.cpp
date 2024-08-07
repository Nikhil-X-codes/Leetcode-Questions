class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        int totalsum=0;
        for(int i:nums){
            totalsum+=i;
        }

        int leftsum=0;

        for(int i=0;i<nums.size();i++){

            if(leftsum == totalsum-leftsum-nums[i]){
return i;
break;
            }
            leftsum+=nums[i];
        }
return -1;   }
};
