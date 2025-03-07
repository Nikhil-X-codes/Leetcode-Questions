class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> mp;  
        vector<string> res;
        int min_sum = INT_MAX;

        for (int i = 0; i < list1.size(); i++) {
            mp[list1[i]] = i;  
        }

        for (int j = 0; j < list2.size(); j++) {
            if (mp.find(list2[j]) != mp.end()) { 
                int index_sum = j + mp[list2[j]];
                
                if (index_sum < min_sum) {  
                    min_sum = index_sum;
                    res = {list2[j]}; 
                } 
                else if (index_sum == min_sum) {  
                    res.push_back(list2[j]);  
                }
            }
        }

        return res;  
    }
};

