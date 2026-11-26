class Solution {
public:
    bool canAliceWin(int n) {

        bool aliceTurn = true;

        for (int i = 10; i > 0; i--) {

            if (n < i) {
                return !aliceTurn;
            }

            n -= i;
            aliceTurn = !aliceTurn;
        }

        return !aliceTurn;
    }
};
