class Solution {
public:
    int scoreDifference(vector<int>& nums) {

        int first = 0;
        int second = 0;
        bool active = true;

        for(int i=0;i<nums.size();i++){

            if(nums[i] % 2 == 1){
                active = !active;
            }

            if(i % 6 == 5){
               active = !active;
            }

            if(active){
                first += nums[i];
            }
            else{
                second += nums[i];
            }
        }

        return first - second;
    }
};
