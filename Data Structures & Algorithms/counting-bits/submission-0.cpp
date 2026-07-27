class Solution {
private:
    int count(int n) {
        int res = 0;
        while(n) {
            n &= (n-1);
            res++;
        }
        return res;
    }
public:
    vector<int> countBits(int n) {
        vector<int> countBits(n+1, 0);
        for(int i=1; i<=n; i++) {
            countBits[i] = count(i);
        }
        return countBits;
    }
};
