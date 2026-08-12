class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        
        int l=0;
        int maxlen = 0;

        int n=nums.size();

        unordered_map<int,int>mp;

        for(int i=0;i<n;i++){

            mp[nums[i]]++;

            while(mp[nums[i]] > k){
                mp[nums[l]]--;

                if(mp[nums[l]] == 0){
                    mp.erase(nums[l]);
                }

                l++;
            }

            maxlen = max(maxlen,i-l+1);
        }

        return maxlen;
    }
};
