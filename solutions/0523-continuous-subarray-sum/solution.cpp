class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        unordered_map<int,int>mp;
        mp[0]=-1;

        int n=nums.size();
        int cummsum=0;

        for(int i=0;i<n;i++){
           cummsum+=nums[i];

           int remainder= (k != 0)  ? cummsum % k : cummsum;

           if(mp.find(remainder) != mp.end()){
             
            if(i - mp[remainder] > 1) return true;
           }

           else{
             mp[remainder] = i;
           }
        }

        return false;
    }
};
