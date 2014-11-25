
class Solution {
    double pow_positive(double x, int n)
    {
        return n == 0 ? 1 : 
            pow_positive(x * x, n / 2) * (n % 2 ? x : 1);
    }


public:
    double pow(double x, int n) {
        return n > 0 ? pow_positive(x, n)
            : (n < 0 ? 1. / pow_positive(x, -n) : 1.);
    }
};
