class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> children(n);
        for (int i = 1; i < n; i++) children[parent[i]].push_back(i);

        vector<int> newParent(parent);
        vector<int> last(26, -1);   // deepest ancestor on current path per char
        vector<int> saved(n, -1);   // previous last[c] to restore on exit
        vector<int> order;          // preorder of original tree
        order.reserve(n);

        // iterative DFS: {node, exiting}
        vector<pair<int, bool>> st;
        st.push_back({0, false});
        while (!st.empty()) {
            auto [node, exiting] = st.back();
            st.pop_back();
            int c = s[node] - 'a';
            if (exiting) {
                last[c] = saved[node];
                continue;
            }
            order.push_back(node);
            if (node != 0 && last[c] != -1) newParent[node] = last[c];
            saved[node] = last[c];
            last[c] = node;
            st.push_back({node, true});
            for (int ch : children[node]) st.push_back({ch, false});
        }

        vector<int> ans(n, 1);
        for (int i = n - 1; i > 0; i--) {
            int node = order[i];
            ans[newParent[node]] += ans[node];
        }
        return ans;
    }
};