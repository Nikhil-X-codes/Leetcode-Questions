class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        
        map<string,int>mp;
        int curr=0;

        for(auto i:arr)mp[i]++;

        for(auto &i:arr){

if(mp[i] > 1)continue;
curr++;

if(curr==k){
return i;   
}

        }
return "";   }
};
