class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        
   int n=A.size();
   vector<int>permut(n+1,0);
   vector<int>res(n, 0);

   int count=0;

    for(int i=0;i<A.size();i++){
    
   permut[A[i]]++;

   if(permut[A[i]] == 2) count++;

    permut[B[i]]++;
    
    if(permut[B[i]] == 2) count++;

    res[i]=count;

    }

 return res;
    }
};
