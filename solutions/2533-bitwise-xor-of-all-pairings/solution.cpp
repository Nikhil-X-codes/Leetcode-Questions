class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        
     int xor1,xor2=0;

     for(int num:nums1){
      xor1^=num;
     }

    for(int num:nums2){
     xor2^=num;
     }

     int m=nums1.size();
     int n=nums2.size();

     int res=0;

     if(m % 2 != 0){
     res^=xor2;
     }

     if(n % 2 != 0){
       res^=xor1;
     }

return res;
    }
};
