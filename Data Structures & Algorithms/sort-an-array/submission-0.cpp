class Solution {
private:
    void mergeSort(vector<int>& arr, int l, int r) {
        if(l >= r) return;
        int m = (l + r) / 2;
        mergeSort(arr, l , m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
    void merge(vector<int>& arr, int l, int m, int r) {
        vector<int> merged;
        int i = l;
        int j = m+1;
        while(i <= m && j <= r) {
            if(arr[i] <= arr[j]) {
                merged.push_back(arr[i++]);
            } else {
                merged.push_back(arr[j++]);
            }
        }
        while(i<=m){
            merged.push_back(arr[i++]);
        }
        while(j<=r){
            merged.push_back(arr[j++]);
        }
        for( int i= l; i <= r; i++){
            arr[i] = merged[i-l];
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};