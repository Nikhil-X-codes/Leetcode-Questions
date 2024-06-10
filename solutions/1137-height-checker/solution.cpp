class Solution {
public:
    int heightChecker(vector<int> heights) {
        int count=0;
        vector<int>expected;
        expected=heights;
        sort(expected.begin(), expected.end());
        for(int i=0;i<expected.size();i++){
if(heights[i] != expected[i])
{
count ++;
}
        }
return count;
    }
};
