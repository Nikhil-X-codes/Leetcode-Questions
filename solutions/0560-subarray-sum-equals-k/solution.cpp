class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int,int>mp;
        mp[0]=1;
        int n=nums.size();

        int prefixsum=0,count=0;

        for(int i=0;i<n;i++){

           prefixsum+=nums[i];

           if(mp.find(prefixsum-k) != mp.end()){
            count+=mp[prefixsum-k];
           }

           mp[prefixsum]++;

        }

        return count;
    }
};
