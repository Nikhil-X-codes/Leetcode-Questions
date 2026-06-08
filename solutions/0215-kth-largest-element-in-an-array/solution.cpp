class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        int n=nums.size();
        vector<int>res;
        
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for(int i=0;i<n;i++){
            
            minHeap.push(nums[i]);
            
            if(minHeap.size() > k){
            minHeap.pop();
            }
        }

        return minHeap.top();
    }
};
