class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum=0;

        int minsize=INT_MAX;

        int high=0,low=0;

        while(high<nums.size()){

sum+=nums[high];
high++;

while(sum >= target){

int currsize=high-low;
minsize=min(currsize,minsize);

sum-=nums[low];
low++;

}

 }
    return (minsize == INT_MAX) ? 0 : minsize;       }
};
