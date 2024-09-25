class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {

    int sum=0;
    int maxsum=0;

    for(int i=0;i<k;i++){
     sum+=cardPoints[i];
    }
    maxsum=sum;

    for(int i=k-1;i>=0;i--){
        sum-=cardPoints[i];
        sum+=cardPoints[cardPoints.size()-k+i];
        maxsum=max(maxsum,sum);
    }

    return maxsum;

    }
};
