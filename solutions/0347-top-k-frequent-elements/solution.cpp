class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int> mp;

        for(int num : nums){
            mp[num]++;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minheap;

        for(auto &element : mp){
            int num = element.first;
            int freq = element.second;

            minheap.push({freq, num});

            if(minheap.size() > k){
                minheap.pop();
            }
        }

        vector<int> res;

        while(!minheap.empty()){
            res.push_back(minheap.top().second);
            minheap.pop();
        }

        return res;
    }
};
