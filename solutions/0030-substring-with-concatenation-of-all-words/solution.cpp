class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
       int n=s.size();
       vector<int>res;

        if (words.empty() || n == 0) return res;

       int wordlen=words[0].size();
       int numwords=words.size();

       int search=wordlen*numwords;
       unordered_map<string,int>wordCount;

       for(string &w:words){
        wordCount[w]++;
       }

       for(int i=0;i<wordlen;i++){

        int left=i,right=i;
        unordered_map<string,int>seen;
        int count=0;

        while(right+wordlen<=n){

            string extractword=s.substr(right,wordlen);
            right+=wordlen;

            if(wordCount.find(extractword) != wordCount.end()){
                seen[extractword]++;
                count++;

               while(seen[extractword] > wordCount[extractword]){
                string leftextractword =s.substr(left,wordlen);
                seen[leftextractword]--;
                left+=wordlen;
                count--;
               }

                if(count == numwords){
                    res.push_back(left);
                }
            }


            else{
              seen.clear();
              count=0;
              left=right;
            }
        }

       }

     return res;
    }
};
