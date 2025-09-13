class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        
        for(int i : nums) sum += i;
        
        double avg = (double)sum / n;
        
        int start = (int)floor(avg) + 1;
        
        start = max(start, 1);
        
        unordered_set<int> s(nums.begin(), nums.end());
        
        while(s.count(start)) {
            start++;
        }
        
        return start;
    }
};
