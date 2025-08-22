class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int minlen=INT_MAX;
        int l=0;
        int currsum=0;

        for(int r=0;r<nums.size();r++){

            currsum+=nums[r];

            while(currsum >= target){
                minlen=min(minlen,r-l+1);
                currsum-=nums[l];
                l++;
            }
        }

        return minlen == INT_MAX ? 0 : minlen;
    }
};
