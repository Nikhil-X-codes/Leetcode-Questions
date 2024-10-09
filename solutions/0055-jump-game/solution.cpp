class Solution {
public:
    bool canJump(vector<int>& nums) {

        int n=nums.size();

        int max_moves=0;

        for(int i=0;i<n;i++){

        if (i >  max_moves){
            return false;
        }
           
         max_moves=max(max_moves,i + nums[i]);

        }

return true;

    }
};
