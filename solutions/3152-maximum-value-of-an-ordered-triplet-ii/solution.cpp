class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        
        int n=nums.size();
         if (n < 3) return 0;

        vector<int>v1(n);
        vector<int>v2(n);
        
       long long res = 0; 

        for(int i=1;i<n;i++){
            v1[i]=max(v1[i-1],nums[i-1]);
        }

        for(int i=n-2;i>=0;i--){
            v2[i]=max(v2[i+1],nums[i+1]);
        }

        for(int i=1;i<n-1;i++){
            res = max(res, (long long)(v1[i] - nums[i]) * v2[i]);
        }

        return res;
    }
};
