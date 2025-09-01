class Solution {
public:

    int leftoccurence(vector<int>& nums, int target,int st,int end){
       int ans=-1;

        while (st <= end) {
            int mid = st + (end - st) / 2;

            if (nums[mid] == target) {
                ans = mid;
                end = mid - 1; 
            } else if (nums[mid] > target) {
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }

        return ans;
    }

    int rightoccurence(vector<int>& nums, int target,int st,int end){
        int ans=-1;
        
        while (st <= end) {
            int mid = st + (end - st) / 2;

            if (nums[mid] == target) {
                ans = mid;
                st=mid+1; 
            } else if (nums[mid] > target) {
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }

        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>res(2);

        res[0]=leftoccurence(nums,target,0,nums.size()-1);
        res[1]=rightoccurence(nums,target,0,nums.size()-1);

        return res;
    }
};
