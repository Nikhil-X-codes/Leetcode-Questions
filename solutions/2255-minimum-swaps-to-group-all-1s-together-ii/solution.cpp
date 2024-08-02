class Solution {
public:
    int minSwaps(vector<int>& nums) {

int n=nums.size();

vector<int>temp(2*n);

for(int i=0;i<2*n;i++){
temp[i]=nums[i%n];
}

int totalones = accumulate(nums.begin(),nums.end(),0);

int i=0,j=0;

int currone=0;
int maxone=0;

while(j < 2*n){

if(temp[j] == 1){
currone++;
}    

if(j-i+1 > totalones){
currone-=temp[i];
i++;
}

maxone=max(maxone,currone);
j++;
}

return totalones- maxone;   }
};
