class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
         
         int n=nums.size();
         vector<int>res(n);

         for(int i=0;i<n;i++){

            if(nums[i] > 0){
               int newindex = (nums[i]+i) % n;
               res[i] = nums[newindex];
            }

            else if(nums[i] < 0){
             int newindex = (nums[i] +i) % n;
              if(newindex < 0) newindex+=n;
              res[i] = nums[newindex];
            }

            else{
                res[i]=0;
            }

         }

         return res;
    }
};
