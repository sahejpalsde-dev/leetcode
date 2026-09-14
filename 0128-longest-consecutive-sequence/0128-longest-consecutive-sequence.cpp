class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        // Insert all elements into an unordered_set for O(1) lookups
        unordered_set<int> numSet(nums.begin(), nums.end());
        int maxLength = 0;

        // Check each number in the set
        for (int num : numSet) {
            // Only start counting if 'num' is the beginning of a sequence
            if (numSet.find(num - 1) == numSet.end()) {
                int currentNum = num;
                int currentStreak = 1;

                // Expand sequence upwards
                while (numSet.find(currentNum + 1) != numSet.end()) {
                    currentNum++;
                    currentStreak++;
                }

                if (currentStreak > maxLength) {
                    maxLength = currentStreak;
                }
            }
        }

        return maxLength;
    }
};