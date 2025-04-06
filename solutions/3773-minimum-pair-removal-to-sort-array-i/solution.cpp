class Solution {
public:

     bool issorted(vector<int>nums){

         for(int i=1;i<nums.size();i++){
         if(nums[i] < nums[i-1]) return false;
         }

         return true;
     }


    int minimumPairRemoval(vector<int>& nums) {

        int count=0;

        while(!issorted(nums)){

            int minisum=INT_MAX;
            int minindex=-1;

            for(int i=0;i<nums.size()-1;i++){
                
                int sum =nums[i]+nums[i+1];

                if(sum < minisum){
                    minisum=sum;
                    minindex=i;
                }
            }

            nums[minindex]=nums[minindex]+nums[minindex+1];
           nums.erase(nums.begin() + minindex + 1);
            count++;
        }

        return count;
    }
};
