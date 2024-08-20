class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        
       map<int,int>mp;

         int mini=0;
         int ans=-1;

        for(int i:nums){
            if(i%2 == 0){
                mp[i]++;
            }
        }

for(auto x:mp){

    if(x.second > mini){

mini = x.second;
ans = x.first;

}

}

return ans;
    }
};
