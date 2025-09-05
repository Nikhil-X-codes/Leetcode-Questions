class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        int n=nums.size();
        int i=0;
        unordered_set<int>s;

        for(int j=0;j<n;j++){
           
           if(s.find(nums[j]) != s.end()){
            return true;
           }

           s.insert(nums[j]);

           if(s.size() > k){
            s.erase(nums[i]);
            i++;
           }

        }

        return false;
    }
};
