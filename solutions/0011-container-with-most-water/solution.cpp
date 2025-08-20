class Solution {
public:
    int maxArea(vector<int>& height) {

        int i=0,j=height.size() -1;
        int sum=0;

        while(i < j){
            int l1=min(height[i],height[j]);
            int l2=j-i;
            int total=l1*l2;

            sum=max(sum,total);
            if(height[i] < height[j]) i++;
            else j--;
        }

          return sum;
    }
};
