class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {

        unordered_map<int,int>mp;
        
        for(int i:nums){
            mp[i]++;
        }

        for(int i=0;i<nums.size();i++){
            
            if(mp[nums[i]] == 1 && nums[i] % 2 == 0 ){
                return nums[i];
            }
        }

        return -1;
    }
};
