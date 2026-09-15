class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        int count = 0;
        int lastEnd = -1; // Tracks the end index of the last chosen non-overlapping palindrome

        // Expand around all possible centers (2 * n - 1 total centers)
        for (int center = 0; center < 2 * n - 1; center++) {
            int left = center / 2;
            int right = left + (center % 2);

            while (left >= 0 && right < n && s[left] == s[right]) {
                int len = right - left + 1;

                // Stop expanding if the palindrome length reaches or exceeds k
                if (len >= k) {
                    // Ensure this palindrome starts after the last chosen palindrome ends
                    if (left > lastEnd) {
                        count++;
                        lastEnd = right; // Lock this palindrome greedily
                    }
                    break; // Stop further expansion from this center
                }

                left--;
                right++;
            }
        }

        return count;
    }
};