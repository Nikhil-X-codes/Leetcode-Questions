class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

set<int>s;

for(int i:nums){
    s.insert(i);
}

int j=0;

for(int i:s){
nums[j++]=i;
}

return s.size();
    }
};
