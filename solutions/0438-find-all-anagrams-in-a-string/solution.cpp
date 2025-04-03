class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        vector<int>res;

        int m=s.size();
        int n=p.size();

        if(n > m) return {};

        unordered_map<char,int>mp1,mp2;

        for(char c:p) mp2[c]++;

        int i=0,j=0;
        int winsize=n;

        while(j < m){
           
           mp1[s[j]]++;

           if(j-i+1 > winsize){

               mp1[s[i]]--;
               
               if(mp1[s[i]] == 0){
                mp1.erase(s[i]);
               }

               i++;
           }

           if(j-i+1 == winsize && mp1 == mp2 ){
             res.push_back(i);
           }

           j++;
        }

return res;
    }
};
