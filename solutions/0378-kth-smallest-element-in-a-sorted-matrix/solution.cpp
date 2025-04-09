class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
    int n=matrix.size();

    int i=matrix[0][0];
    int j=matrix[n-1][n-1];
    
    while(i < j){

        int mid=i+(j-i)/2;
        int row=n-1,col=0;
        int count=0;

        while(row >= 0 && col < n){

        if(matrix[row][col] <= mid){
           count+=row+1;
           col++;
        }

        else row--;

        }

        if(count < k) i=mid+1;

        else j=mid;


    }

 return i; 
    }
};
