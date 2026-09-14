class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};

        // Step 1: Sort intervals based on their start values
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;
        // Start with the first interval
        merged.push_back(intervals[0]);

        // Step 2: Iterate through the remaining intervals
        for (int i = 1; i < intervals.size(); i++) {
            // Get reference to the last merged interval
            vector<int>& last = merged.back();

            // If current interval overlaps with the last merged interval
            if (intervals[i][0] <= last[1]) {
                // Expand the end boundary to cover both intervals
                if (intervals[i][1] > last[1]) {
                    last[1] = intervals[i][1];
                }
            } else {
                // No overlap, append as a new interval
                merged.push_back(intervals[i]);
            }
        }

        return merged;
    }
};