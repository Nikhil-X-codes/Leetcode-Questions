class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;

        int count=0;

        int cummsum=0;

        mp.insert({0, 1});
    
        for(int i=0;i<nums.size();i++){
          
          cummsum+=nums[i];

          if(mp.find (cummsum -k) != mp.end()){
            count+=mp[cummsum -k];
          }

          mp[cummsum]++;
  
        }

return count;
    }
};
