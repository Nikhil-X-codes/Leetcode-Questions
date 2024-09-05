class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
vector<int>positives;
vector<int>negatives;

for(auto &num:nums){

if(num > 0){
 positives.push_back(num);
}

else{
negatives.push_back(num);
 }

}

vector<int>res;
int i=0,j=0;

while(i < positives.size() and j < negatives.size()){

    res.push_back(positives[i]);
    i++;

    res.push_back(negatives[j]);
     j++;

}
return res;
    }
};
