class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        deque<pair<long long, long long>> dq;       // blocks of equal prefix maximum: (value, how many positions)
        long long S = 0;                            // sum of prefix maxima over the window [l..r]
        long long sumNums = 0;                      // sum of nums over the window [l..r]
        long long ans = 0;
        int r = n - 1;

        for (int l = n - 1; l >= 0; l--) {
            // add nums[l] on the left: it becomes the prefix max for everything up to the next larger value
            long long cnt = 1;
            sumNums += nums[l];
            while (!dq.empty() && dq.front().first <= nums[l]) {
                S -= dq.front().first * dq.front().second;
                cnt += dq.front().second;
                dq.pop_front();
            }
            dq.push_front({nums[l], cnt});
            S += (long long)nums[l] * cnt;

            // shrink from the right until the cost fits in k
            while (S - sumNums > k) {
                sumNums -= nums[r];
                S -= dq.back().first;
                if (--dq.back().second == 0) dq.pop_back();
                r--;
            }
            ans += r - l + 1;                       // every [l..j] with j <= r works
        }
        return ans;
    }
};