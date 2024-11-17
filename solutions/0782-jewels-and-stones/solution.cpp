class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        
        int count=0;

        unordered_map<char,int>mp;

        for(char &c :jewels){
         mp[c]++;
        }

        for(int i=0;i<stones.size();i++){
         
         if(mp.find(stones[i]) != mp.end()) count++;

        }
return count;
    }
};
