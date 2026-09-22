class Solution {
public:
    int n, K;
    vector<int> segP;
    vector<int> segCnt; // flattened: node*K*K + a*K + b

    inline int idx(int node, int a, int b) { return node * K * K + a * K + b; }

    void setLeaf(int node, int v) {
        v %= K;
        segP[node] = v;
        for (int a = 0; a < K; a++) {
            for (int b = 0; b < K; b++) segCnt[idx(node, a, b)] = 0;
            segCnt[idx(node, a, (a * v) % K)] = 1;
        }
    }

    void pull(int node) {
        int l = 2 * node, r = 2 * node + 1;
        segP[node] = (segP[l] * segP[r]) % K;
        for (int a = 0; a < K; a++) {
            int ap = (a * segP[l]) % K;
            for (int b = 0; b < K; b++) {
                segCnt[idx(node, a, b)] = segCnt[idx(l, a, b)] + segCnt[idx(r, ap, b)];
            }
        }
    }

    void build(int node, int l, int r, vector<int>& nums) {
        if (l == r) { setLeaf(node, nums[l]); return; }
        int mid = (l + r) / 2;
        build(2*node, l, mid, nums);
        build(2*node+1, mid+1, r, nums);
        pull(node);
    }

    void update(int node, int l, int r, int pos, int val) {
        if (l == r) { setLeaf(node, val); return; }
        int mid = (l + r) / 2;
        if (pos <= mid) update(2*node, l, mid, pos, val);
        else update(2*node+1, mid+1, r, pos, val);
        pull(node);
    }

    int query(int node, int l, int r, int ql, int qr, int &a, int x) {
        if (qr < l || r < ql) return 0;
        if (ql <= l && r <= qr) {
            int res = segCnt[idx(node, a, x)];
            a = (a * segP[node]) % K;
            return res;
        }
        int mid = (l + r) / 2;
        int res = query(2*node, l, mid, ql, qr, a, x);
        res += query(2*node+1, mid+1, r, ql, qr, a, x);
        return res;
    }

    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        n = nums.size();
        K = k;
        segP.assign(4 * n, 1);
        segCnt.assign(4 * n * K * K, 0);
        build(1, 0, n - 1, nums);

        vector<int> result;
        result.reserve(queries.size());
        for (auto& q : queries) {
            int index = q[0], value = q[1], start = q[2], x = q[3];
            update(1, 0, n - 1, index, value);
            int a = 1 % K;
            result.push_back(query(1, 0, n - 1, start, n - 1, a, x));
        }
        return result;
    }
};