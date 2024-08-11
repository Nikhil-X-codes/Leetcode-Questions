class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_map<int, int> map;
        vector<int> result;

        for(int num:nums1){
            map[num]=1;
        }

        for(int &num : nums2){

            if(map[num] == 1 and map.find(num) != map.end()){
          result.push_back(num);
          map[num] = 0; 
            }
        }
        return result;
    }
};
