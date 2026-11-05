class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int count = 0;

        for (int x : arr1) {
            // first value in arr2 that is >= x - d
            auto it = lower_bound(arr2.begin(), arr2.end(), x - d);
            // if it exists and is within x + d, then |x - that value| <= d, so x fails
            if (it == arr2.end() || *it > x + d) count++;
        }
        return count;
    }
};