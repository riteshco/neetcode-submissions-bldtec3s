class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;
        bool neg = false;
        if(n < 0) {
            n *= -1;
            neg = true;
        }
        double ans = 1;
        while(n > 0) {
            ans *= x;
            n--;
        }
        return neg ? 1.0/ans : ans;
    }
};
