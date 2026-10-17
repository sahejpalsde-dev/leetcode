class Solution {
    int digitSum(int x) {
        int s = 0;
        while (x) { s += x % 10; x /= 10; }
        return s;
    }

public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        // (digit sum, value, original index)
        vector<array<int, 3>> a(n);
        for (int i = 0; i < n; i++)
            a[i] = {digitSum(nums[i]), nums[i], i};

        sort(a.begin(), a.end());               // by digit sum, then by value

        // a[t][2] = original index of the element that belongs at position t
        vector<bool> vis(n, false);
        int cycles = 0;
        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;
            cycles++;
            int j = i;
            while (!vis[j]) {                   // walk the cycle
                vis[j] = true;
                j = a[j][2];
            }
        }
        return n - cycles;
    }
};