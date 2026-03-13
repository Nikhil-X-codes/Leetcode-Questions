class Solution {
public:

    vector<int> sortedSquares(vector<int>& nums) {

        int n=nums.size();
        vector<int>res(n,0);

        int i=0,j=n-1;
        int k = n-1;

        while(i <= j && k >= 0){
           int lefty = nums[i] * nums[i];
           int righty = nums[j] * nums[j];

           if(lefty < righty){
             res[k] = righty;
             j--;
             k--;
           }

           else{
              res[k] = lefty;
             i++;
             k--;
           }

        }

        return res;
    }
};
