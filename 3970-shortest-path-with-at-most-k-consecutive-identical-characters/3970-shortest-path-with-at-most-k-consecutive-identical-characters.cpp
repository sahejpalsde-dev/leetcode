class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& e : edges) adj[e[0]].push_back({e[1], e[2]});

        const long long INF = LLONG_MAX / 4;
        // dist[u][r] = cheapest cost to reach u with a run of r identical labels ending at u
        vector<vector<long long>> dist(n, vector<long long>(k + 1, INF));

        using T = tuple<long long, int, int>;                 // (cost, node, run length)
        priority_queue<T, vector<T>, greater<T>> pq;

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [d, u, r] = pq.top();
            pq.pop();
            if (d > dist[u][r]) continue;                      // stale entry
            if (u == n - 1) return (int)d;                     // first pop of the target is optimal

            for (auto [v, w] : adj[u]) {
                int nr = (labels[v] == labels[u]) ? r + 1 : 1; // extend or restart the run
                if (nr > k) continue;                          // too many identical labels in a row
                if (d + w < dist[v][nr]) {
                    dist[v][nr] = d + w;
                    pq.push({d + w, v, nr});
                }
            }
        }
        return -1;
    }
};