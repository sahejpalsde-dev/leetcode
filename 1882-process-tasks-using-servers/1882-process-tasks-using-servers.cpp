class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size(), m = tasks.size();

        using F = pair<int, int>;                               // (weight, index)
        priority_queue<F, vector<F>, greater<F>> freeQ;
        using B = tuple<long long, int, int>;                   // (time free again, weight, index)
        priority_queue<B, vector<B>, greater<B>> busyQ;

        for (int i = 0; i < n; i++) freeQ.push({servers[i], i});

        vector<int> ans(m);
        long long t = 0;                                        // current time
        for (int j = 0; j < m; j++) {
            t = max(t, (long long)j);                           // task j arrives at second j
            if (freeQ.empty())                                  // nobody free: jump to the first release
                t = max(t, get<0>(busyQ.top()));

            while (!busyQ.empty() && get<0>(busyQ.top()) <= t) {   // release finished servers
                auto [ft, w, id] = busyQ.top();
                busyQ.pop();
                freeQ.push({w, id});
            }

            auto [w, id] = freeQ.top();                         // lightest, then lowest index
            freeQ.pop();
            ans[j] = id;
            busyQ.push({t + tasks[j], w, id});
        }
        return ans;
    }
};