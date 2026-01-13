class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
        int sum=0,left=0;
        int maxsum=INT_MIN;
        unordered_set<int>st;

        for(int right=0;right<nums.size();right++){
            
            sum+=nums[right];

            while(st.find(nums[right]) != st.end()){
               st.erase(nums[left]);
               sum-=nums[left];
               left++;
            }

            st.insert(nums[right]);

            maxsum=max(maxsum,sum);
        }

        return maxsum;
    }
};
