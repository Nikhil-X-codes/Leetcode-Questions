class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {

        int sum1=0;
        int maxisum = INT_MIN;
        int minisum= INT_MAX;

        int n=nums.size();

        for(int i=0;i<n;i++){           
            sum1+=nums[i];
            maxisum=max(maxisum,sum1);
            if(sum1 < 0) sum1=0;
        }
        
        int sum2=0;
                                              
        for(int i=0;i<n;i++){                
            sum2+=nums[i];
            minisum=min(minisum,sum2);
            if(sum2 > 0) sum2=0;
        }
        
        return max(abs(maxisum),abs(minisum));
        
    }
};
