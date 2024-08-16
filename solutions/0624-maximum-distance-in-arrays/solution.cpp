class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        
        int mini=arrays[0].front();

        int maxi=arrays[0].back();

int res=0;

    for(int i=1;i < arrays.size();i++){

            int curr_mini=arrays[i].front();

            int curr_maxi=arrays[i].back();

 res=max({res,abs(curr_mini - maxi),abs(mini - curr_maxi)});

 mini=min(mini,curr_mini);

 maxi=max( maxi, curr_maxi);

        }
return res;
    }
};
