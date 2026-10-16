class Solution {
    static const long long MOD = 1e9 + 7;
    vector<long long> s, q, lz;   // sum, sum of squares, lazy add

    void apply(int o, int len, long long v) {
        q[o] = (q[o] + 2 * v % MOD * s[o] + v * v % MOD * len) % MOD;   // uses the old sum
        s[o] = (s[o] + v * len) % MOD;
        lz[o] += v;
    }

    void push(int o, int l, int r) {
        if (lz[o] == 0) return;
        int m = (l + r) / 2;
        apply(2 * o,     m - l + 1, lz[o]);
        apply(2 * o + 1, r - m,     lz[o]);
        lz[o] = 0;
    }

    void update(int o, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            apply(o, r - l + 1, 1);
            return;
        }
        push(o, l, r);
        int m = (l + r) / 2;
        if (ql <= m) update(2 * o, l, m, ql, qr);
        if (qr > m)  update(2 * o + 1, m + 1, r, ql, qr);
        s[o] = (s[2 * o] + s[2 * o + 1]) % MOD;
        q[o] = (q[2 * o] + q[2 * o + 1]) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        s.assign(4 * n, 0);
        q.assign(4 * n, 0);
        lz.assign(4 * n, 0);

        unordered_map<int, int> last;       // last index of each value
        long long ans = 0;

        for (int j = 0; j < n; j++) {
            int prev = last.count(nums[j]) ? last[nums[j]] : -1;
            update(1, 0, n - 1, prev + 1, j);   // d[i] += 1 for i in (prev, j]
            ans = (ans + q[1]) % MOD;           // add the sum of d[i]^2 for this right end
            last[nums[j]] = j;
        }
        return (int)ans;
    }
};