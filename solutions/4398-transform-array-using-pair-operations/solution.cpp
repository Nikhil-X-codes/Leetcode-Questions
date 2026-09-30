class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) {

        long long src = accumulate(source.begin(), source.end(), 0LL);
        long long dst = accumulate(target.begin(), target.end(), 0LL);

        if (src != dst)
            return false;

        return true;
    }
};
