class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i,j=0;
        int n=nums.size();
        int zerocount=0;
        int maxlen=INT_MIN;

        while(j < n){

            if(nums[j] == 0) zerocount++;

            while(zerocount > k){

                if(nums[i] == 0) zerocount--;

                i++;
            }

            maxlen=max(maxlen,j-i+1);
            j++;
        }

        return maxlen;
    }
};
