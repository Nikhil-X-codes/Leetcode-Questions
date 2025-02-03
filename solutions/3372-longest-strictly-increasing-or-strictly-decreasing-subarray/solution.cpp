class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int countinc = 1, countdec = 1; // Initialize properly
        int maxlen = 1; 
        
        int n = nums.size();

        for (int i = 0; i < n - 1; i++) {

            if (nums[i] < nums[i + 1]) { 
                countinc++;
                countdec = 1;  
            } 

            else if (nums[i] > nums[i + 1]) {  
                countdec++;
                countinc = 1;  
            } 

            
            else {  
                countinc = countdec = 1;
            }

            maxlen = max(maxlen, max(countinc, countdec));
        }

        return maxlen;
    }
};

