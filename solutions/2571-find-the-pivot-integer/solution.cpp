class Solution {
public:
    int pivotInteger(int n) {
      
        int a = (n*(n+1))/2;
        int sr = sqrt(a);
        if(sr*sr == a) return sr;

        return -1;
    }
};
