class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        int n = digits.size();
        vector<int> newDigits;
        reverse(digits.begin(), digits.end());
        for(int i=0; i<n; i++) {
            int sum = digits[i] + carry;
            if(i==0) {
                sum += 1;
            }
            if(sum > 9) {
                sum = sum%10;
                carry = 1;
            } else carry = 0;
            newDigits.push_back(sum);
        }
        if(carry) newDigits.push_back(carry);
        reverse(newDigits.begin(), newDigits.end());
        return newDigits;
    }
};
