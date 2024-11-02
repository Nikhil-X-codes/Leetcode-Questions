class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

     vector<vector<int>> result;

    sort(nums.begin(), nums.end());

    for(int k=0;k<nums.size();k++){
        
        if (k > 0 && nums[k] == nums[k - 1]) continue;
        
       int i=k+1,j=nums.size()-1;

       while(i<j){

        int sum=nums[i]+nums[j]+nums[k];

        if(sum > 0) j--;

        else if(sum < 0)i++;

        else{

         result.push_back({nums[i], nums[j], nums[k]});

         while(i<j and nums[i]==nums[i+1])i++;
         while(i<j and nums[j] == nums[j-1])j--;
          i++;
          j--;

        }


       }

    }

return result;
    }
};
