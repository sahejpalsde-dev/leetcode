class Solution {
public:
    double myPow(double x, int n) {
        long double base = x;                      // 64-bit mantissa instead of 53 bits
        long long p = llabs((long long)n);         // work with |n|; also safe for INT_MIN
        long double ans = 1;

        while (p > 0) {
            if (p & 1) ans *= base;                // this bit of the exponent is set
            base *= base;                          // base, base^2, base^4, ...
            p >>= 1;
        }
        return n < 0 ? (double)(1.0L / ans) : (double)ans;   // invert once, at the end
    }
};