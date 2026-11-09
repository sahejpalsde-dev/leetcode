class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> avail;                                          // free servers, kept sorted by id
        for (int i = 0; i < k; i++) avail.insert(i);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> busy;   // (end time, server)
        vector<int> cnt(k, 0);

        for (int i = 0; i < (int)arrival.size(); i++) {
            while (!busy.empty() && busy.top().first <= arrival[i]) {   // free servers that finished
                avail.insert(busy.top().second);
                busy.pop();
            }
            if (avail.empty()) continue;                         // all busy: drop the request

            auto it = avail.lower_bound(i % k);                  // first free server >= i % k
            if (it == avail.end()) it = avail.begin();           // wrap around
            int s = *it;
            avail.erase(it);
            cnt[s]++;
            busy.push({arrival[i] + load[i], s});
        }

        int mx = *max_element(cnt.begin(), cnt.end());
        vector<int> ans;
        for (int i = 0; i < k; i++) if (cnt[i] == mx) ans.push_back(i);
        return ans;
    }
};