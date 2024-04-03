//https://leetcode.com/problems/powx-n/submissions/1190358303/

class Solution {
public:
    double myPow(double x, int n) {

        if (x == 1 || n == 0)
            return 1;
        if (x == 1)
            return (n % 2) ? -1 : 1;

        double result = 1;
        int N = abs(n);
        while (N > 0) {
            if (N % 2 == 1) {
                result *= x;
            }
            x *= x;
            N /= 2;
        }

        if (n > 0)
            return result;
        else
            return 1 / result;
    }
};
