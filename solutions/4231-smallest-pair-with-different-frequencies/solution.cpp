class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {

        vector<int>res;
        unordered_map<int,int>mp;
        
        for(int i:nums){
            mp[i]++;
        }

        for(auto &p:mp){
            res.push_back(p.first);
        }

        sort(res.begin(),res.end());

        int n = res.size();

        for(int i=0;i<n;i++){

            for(int j=i+1;j<n;j++){
                if(mp[res[i]] != mp[res[j]]){
                    return {res[i], res[j]};
                }
            }
        }
        
        return {-1,-1};
    }
};
