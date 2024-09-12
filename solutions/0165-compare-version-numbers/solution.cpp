class Solution {
public:
    int compareVersion(string version1, string version2) {
        
        int m=version1.size();
        int n=version2.size();

        int n1,n2;
        int i=0,j=0;

        while(i < m or j < n){
            n1=0;
            n2=0;

            while(i < m and version1[i] != '.'){
                n1=n1*10+(version1[i] - '0');
                i++;
            }

            while(j < n and version2[j] != '.'){
                n2=n2*10+(version2[j] - '0');
                j++;
            }

            if(n1 < n2) return -1;
            if(n2 < n1) return 1;

            i++;
            j++;
        }
return 0;        
    }
};
