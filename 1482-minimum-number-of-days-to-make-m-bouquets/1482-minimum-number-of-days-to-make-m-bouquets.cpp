class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long totalFlowersNeeded = (long long)m * k;
        if (totalFlowersNeeded > bloomDay.size()) return -1;

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (canMakeBouquets(bloomDay, m, k, mid)) {
                high = mid;   // try to find an even earlier day
            } else {
                low = mid + 1;  // need more time
            }
        }

        return low;
    }

private:
    // Can we make m bouquets of k adjacent flowers each, by day "day"?
    bool canMakeBouquets(vector<int>& bloomDay, int m, int k, int day) {
        int bouquets = 0, consecutive = 0;

        for (int bloom : bloomDay) {
            if (bloom <= day) {
                consecutive++;
                if (consecutive == k) {
                    bouquets++;
                    consecutive = 0;  // reset, start counting a fresh group
                }
            } else {
                consecutive = 0;  // streak broken, flower not bloomed yet
            }
        }

        return bouquets >= m;
    }
};