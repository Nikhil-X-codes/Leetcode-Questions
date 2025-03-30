class Solution {
public:
    int minStartValue(vector<int>& nums) {
        
        int mini=0,cummsum=0;

        for(int i=0;i<nums.size();i++){
            cummsum += nums[i];

            mini=min(mini,cummsum);
        }

        int intial=1-mini;

        return intial;
    }
};
