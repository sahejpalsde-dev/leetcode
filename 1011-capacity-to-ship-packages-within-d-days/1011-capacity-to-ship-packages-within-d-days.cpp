#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
    
        int start = *max_element(weights.begin(), weights.end());
        int end = accumulate(weights.begin(), weights.end(), 0);
        
        int value = end;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            int count = 1;
            int ans = 0;

            for (int i = 0; i < weights.size(); i++) {
                if (ans + weights[i] > mid) {
                    count++;           // Start a new day
                    ans = 0;        // Reset ship load for the new day
                }
                ans += weights[i];  // Add item to current day's load
            }

            if (count <= days) {
                value = mid;
                end = mid - 1;
            } else {
               
                start = mid + 1;
            }
        }

        return value;
    }
};