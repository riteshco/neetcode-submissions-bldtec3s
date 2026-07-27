class Solution {
public:
    bool isHappy(int n) {
        vector<bool> seen(1001, false);
        while(n != 1) {
            int ones = n%10;
            int tens = (n/10)%10;
            int hundreds = ((n/10)/10)%10;
            int thousands = (((n/10)/10)/10)%10;
            n = ones*ones + tens*tens + hundreds*hundreds + thousands*thousands;
            if(seen[n]) return false;
            else seen[n] = true;
        }
        return true;
    }
};
