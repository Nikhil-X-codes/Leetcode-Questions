class Solution {
public:
    string numberToWords(int num) {
        vector<string> lessThan10 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
        vector<string> tens = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        vector<string> lessThan20 = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

        if (num == 0) {
            return "Zero";
        } else if (num < 10) {
            return lessThan10[num];
        } else if (num < 20) {
            return lessThan20[num - 10];
        } else if (num < 100) {
            return tens[num / 10] + (num % 10 ? " " + lessThan10[num % 10] : "");
        } else if (num < 1000) {
            return lessThan10[num / 100] + " Hundred" + (num % 100 ? " " + numberToWords(num % 100) : "");
        } else if (num < 1000000) {
            return numberToWords(num / 1000) + " Thousand" + (num % 1000 ? " " + numberToWords(num % 1000) : "");
        } else if (num < 1000000000) {
            return numberToWords(num / 1000000) + " Million" + (num % 1000000 ? " " + numberToWords(num % 1000000) : "");
        } else {
            return numberToWords(num / 1000000000) + " Billion" + (num % 1000000000 ? " " + numberToWords(num % 1000000000) : "");
        }
    }
};

