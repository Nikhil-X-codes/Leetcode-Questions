class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        map<int,int>mp;

        for(int i:nums){
            mp[i]++;
        }
   
    vector<int> result; 

        for(auto &i:mp){

            if(i.second > (n/3)){
         result.push_back(i.first);
            }
        }
        return result;
    }
};
