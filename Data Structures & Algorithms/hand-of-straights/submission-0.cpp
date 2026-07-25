class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int> freq;
        for(int h : hand) {
            freq[h]++;
        }
        while(!freq.empty()) {
            int num = freq.begin()->first;
            int count = freq.begin()->second;
            for(int i=0; i<groupSize; i++) {
                if(freq.find(num + i) == freq.end() || freq[num + i] < count) return false;
                freq[num + i] -= count;
                if(freq[num + i] == 0) freq.erase(num+i);
            }
        }
        return true;
    }
};
