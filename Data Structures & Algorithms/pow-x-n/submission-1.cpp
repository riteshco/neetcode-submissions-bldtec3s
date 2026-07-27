class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;
        if(x==0) return 0;
        bool neg = false;
        if(n < 0) {
            n *= -1;
            neg = true;
        }
        double ans = 1;
        while(n > 0) {
            if(n%2){
                ans *= x;
                n--;
            }
            if(n > 1){
                x *= x;
                n>>=1;
            }
        }
        return neg ? 1.0/ans : ans;
    }
};
