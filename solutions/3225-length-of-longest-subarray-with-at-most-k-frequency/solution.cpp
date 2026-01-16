class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        
        int left=0;
        unordered_map<int,int>mp;
        int maxlen=INT_MIN;

        for(int right=0;right<nums.size();right++){

            mp[nums[right]]++;

            while(mp[nums[right]] > k){
               
               mp[nums[left]]--;

               if(mp[nums[left]] == 0){
                mp.erase(nums[left]);
               }

               left++;
            }

            if(mp[nums[right]] <= k){
                maxlen=max(maxlen,right-left+1);
            }

        }

        return maxlen;
    }
};
