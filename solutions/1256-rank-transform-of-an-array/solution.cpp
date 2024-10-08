class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
         
         int n=arr.size();

         vector<int>res;

         if(n==0) return {};

         set<int> uniqueElements(arr.begin(), arr.end());

         int rank=1;

         map<int,int>mp;

         for(int m:uniqueElements){
            mp[m]=rank++;
         }

            for (int &m : arr)
            res.push_back(mp[m]);


         return res;
    }
};
