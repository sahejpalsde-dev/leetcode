class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        // is nums a rotation of the ascending sequence 0..n-1, or of the descending one?
        bool asc = true, desc = true;
        for (int i = 0; i < n; i++) {
            if (nums[i] != (nums[0] + i) % n) asc = false;
            if (nums[i] != ((nums[0] - i) % n + n) % n) desc = false;
        }
        if (!asc && !desc) return -1;            // no sequence of operations can sort it

        int ans = INT_MAX;

        if (asc) {
            int a = (n - nums[0]) % n;           // left rotations needed
            if (a == 0) ans = 0;
            else ans = min(a, n - a + 2);        // rotate a times, or reverse + rotate (n-a) + reverse
        }

        if (desc) {
            // option 1: reverse first, then rotate left
            int a = (n - nums[n - 1]) % n;       // after reversing, the first element is nums[n-1]
            ans = min(ans, 1 + a);

            // option 2: rotate left until n-1 is at the front, then reverse
            int pos = find(nums.begin(), nums.end(), n - 1) - nums.begin();
            ans = min(ans, pos + 1);
        }
        return ans;
    }
};