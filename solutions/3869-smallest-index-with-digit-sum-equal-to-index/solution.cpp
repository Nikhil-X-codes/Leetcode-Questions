class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        
        int n = nums.size();

        for(int i=0;i<n;i++){

            int element = nums[i];
            int sum = 0;

            while(element){
                int digit = element % 10;
                sum += digit;
                element = element/10;
            }
            
            if(sum == i){
                return i;
            }

        }

        return -1;
    }
};
