class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        
                vector<int>ans;
        int p = n;
        int j = 0;
        while(p<2*n){
            ans.push_back(nums[j]);
            j++;
            ans.push_back(nums[p]);
            p++;
        }
        return ans;
    }
};
