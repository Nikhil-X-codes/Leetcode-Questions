class Solution {
public:
    int minOperations(vector<int>& nums) {
    
        int n=nums.size();

        if (n ==1) return 0;

        int ans = 0;

        vector<int>temp = nums;

        for(int i=0;i<n-1;i++)
        {
            if(temp[i] >= temp[i+1])
                temp[i+1] = temp[i]+1;
        }

        for(int i=0;i<n;i++)
            ans += temp[i] - nums[i];


        return ans;

    }
};
