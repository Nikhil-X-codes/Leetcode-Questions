class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
      
    int n=s.size();

    vector<int>res(n,0);
   
    for(auto &i:shifts){
      
      int start = i[0], middle = i[1],end=i[2];
      int x;

      if(end == 0){
        x=-1;
      }

      else{
        x=1;
      }

      res[start]+=x;

      if(middle+1 < n){
      res[middle+1]-=x;
      }


    }
    
    for(int i=1;i<n;i++){
      res[i]+=res[i-1];
    }

    for(int i=0;i<n;i++){

      int shift=res[i] % 26;

      if(shift < 0){
        shift+=26;
      }
      
    s[i] = ((s[i] - 'a') + shift) % 26 + 'a';
      
    }

return s;
    }
};
