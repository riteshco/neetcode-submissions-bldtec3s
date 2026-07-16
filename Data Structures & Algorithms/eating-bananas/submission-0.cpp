class Solution {
private:
    bool satisfy(vector<int>& piles, int mid, int h) {
        int needed = 0;
        for(int pile: piles) {
            if(pile <= mid) needed++;
            else {
                needed += pile/mid;
                if(pile%mid) needed++;
            }    
        }
        return needed <= h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = 0;
        for(int p : piles) right = max(right, p);
        int ans = 0;
        while(left <= right) {
            int mid = (left + right) >> 1;
            if(satisfy(piles, mid, h)) {
                ans = mid;
                right = mid - 1;
            } else left = mid + 1;
        }
        return ans;
    }
};
