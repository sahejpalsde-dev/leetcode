class Solution {
    int n, LOG;
    vector<int> tin, tout, depth, init, bitTree;
    vector<vector<int>> up;

    // Fenwick tree over XOR: range-xor update, point query
    void upd(int i, int v) { for (i++; i <= n + 1; i += i & -i) bitTree[i] ^= v; }
    int qry(int i)         { int r = 0; for (i++; i > 0; i -= i & -i) r ^= bitTree[i]; return r; }

    int lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);
        for (int j = 0; j < LOG; j++)
            if ((depth[u] - depth[v]) >> j & 1) u = up[j][u];
        if (u == v) return u;
        for (int j = LOG - 1; j >= 0; j--)
            if (up[j][u] != up[j][v]) { u = up[j][u]; v = up[j][v]; }
        return up[0][u];
    }

    int pathToRoot(int x) { return init[tin[x]] ^ qry(tin[x]); }   // xor mask of root..x

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        this->n = n;
        LOG = 1;
        while ((1 << LOG) < n) LOG++;

        vector<vector<int>> adj(n);
        for (auto& e : edges) { adj[e[0]].push_back(e[1]); adj[e[1]].push_back(e[0]); }

        tin.assign(n, 0); tout.assign(n, 0); depth.assign(n, 0);
        init.assign(n, 0); bitTree.assign(n + 2, 0);
        up.assign(LOG, vector<int>(n, 0));

        // iterative DFS from node 0
        vector<int> mask(n, 0), it(n, 0), st = {0};
        int timer = 0;
        mask[0] = 1 << (s[0] - 'a');
        tin[0] = timer++; init[tin[0]] = mask[0];
        while (!st.empty()) {
            int u = st.back();
            if (it[u] < (int)adj[u].size()) {
                int v = adj[u][it[u]++];
                if (v == up[0][u] && u != 0) continue;       // skip the parent
                if (v == 0) continue;                        // root is never a child
                up[0][v] = u;
                depth[v] = depth[u] + 1;
                mask[v] = mask[u] ^ (1 << (s[v] - 'a'));
                tin[v] = timer++;
                init[tin[v]] = mask[v];
                st.push_back(v);
            } else {
                tout[u] = timer - 1;                         // last tin inside u's subtree
                st.pop_back();
            }
        }
        for (int j = 1; j < LOG; j++)
            for (int v = 0; v < n; v++)
                up[j][v] = up[j - 1][up[j - 1][v]];

        vector<bool> ans;
        for (auto& q : queries) {
            istringstream ss(q);
            string type, a, b;
            ss >> type >> a >> b;
            if (type == "update") {
                int x = stoi(a);
                char c = b[0];
                if (s[x] == c) continue;
                int d = (1 << (s[x] - 'a')) ^ (1 << (c - 'a'));
                s[x] = c;
                upd(tin[x], d);                              // every node in x's subtree flips by d
                upd(tout[x] + 1, d);
            } else {
                int u = stoi(a), v = stoi(b);
                int l = lca(u, v);
                int m = pathToRoot(u) ^ pathToRoot(v) ^ (1 << (s[l] - 'a'));
                ans.push_back((m & (m - 1)) == 0);           // at most one odd-count letter
            }
        }
        return ans;
    }
};