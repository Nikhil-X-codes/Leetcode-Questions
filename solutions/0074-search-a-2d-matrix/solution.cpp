class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
         
           int m = matrix.size();
            int n = matrix[0].size();

        int st=0,end=(m*n)-1;

        while(st <= end){
          int mid=st+(end-st)/2;

               int row = mid / n;
            int col = mid % n;

          if(matrix[row][col] == target){
           return true;
           break;
          }

          else if(matrix[row][col] > target){
end=mid-1;
          }

          else{
            st=mid+1;
          }

        }
return false; 
    }
}; 
