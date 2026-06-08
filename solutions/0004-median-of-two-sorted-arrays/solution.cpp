class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;

        // helper function just like median in stream

        auto addnum = [&](int num) {
            maxHeap.push(num);

            minHeap.push(maxHeap.top());
            maxHeap.pop();

            if (minHeap.size() > maxHeap.size()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        };

        for (int x : nums1)
            addnum(x);

        for (int x : nums2)
            addnum(x);

        if (maxHeap.size() == minHeap.size()) {
            return ((double)maxHeap.top() + minHeap.top()) / 2.0;
        }

        return maxHeap.top();
    }
};
