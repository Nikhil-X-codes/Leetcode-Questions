class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        
        int n=nums.size();

        if(n == 1) return 0;

        int val=0;
        int sum = accumulate(nums.begin(),nums.end(),0);

        for(int i=0;i<n;i++){
            val += i * nums[i];
        }

        int maxsum = val;

        for(int k=1;k<n;k++){
           val = val + sum - (n * nums[n-k]);

           maxsum = max(maxsum,val);
        }
        
        return maxsum;
    }
};
