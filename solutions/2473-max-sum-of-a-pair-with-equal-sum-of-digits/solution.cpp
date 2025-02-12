class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;

        int maxsum=-1;

    auto digitSum = [](int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
};

      for(int i:nums){

        int sums=digitSum(i);

        if(mp.find(sums) != mp.end()) {
           maxsum=max(maxsum,mp[sums]+i);
        }

        mp[sums]=max(mp[sums],i);

      }

return maxsum;
    }
};
