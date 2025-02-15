class Solution {
public:
    bool ispart(string& str, int target, int index = 0, int currsum = 0) {

        if (index >= str.size())
            return currsum == target;

         int partsum = 0;

        for (int i = index; i < str.size(); i++) {
            partsum = partsum * 10 + (str[i] - '0');

            if (partsum + currsum > target)
                break;

            if (ispart(str, target, i + 1, currsum + partsum)) {
                return true;
            }
        }

        return false;
    }

    int punishmentNumber(int n) {

        int totalsum = 0;

        for (int i = 1; i <= n; i++) {
          
           string squareStr = to_string(i * i);

            if (ispart(squareStr,i)) {
                totalsum += (i * i);
            }
        }

        return totalsum;
    }
};
