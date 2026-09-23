class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int total = 0;

        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);

            for (int j = i; j < n; j++) {
                // Track frequency of characters in substring s[i..j]
                freq[s[j] - 'a']++;

                int maxi = 0;
                int mini = INT_MAX;

                // Find max and min non-zero frequency in current substring
                for (int k = 0; k < 26; k++) {
                    if (freq[k] > 0) {
                        maxi = max(maxi, freq[k]);
                        mini = min(mini, freq[k]);
                    }
                }

                // Add the beauty of substring s[i..j] to running total
                total += (maxi - mini);
            }
        }

        return total;
    }
};