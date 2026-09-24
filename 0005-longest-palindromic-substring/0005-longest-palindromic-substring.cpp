class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";

        int start = 0, maxLen = 1;

        for (int i = 0; i < s.size(); i++) {
            // Odd-length palindromes (center = single char at i)
            int l1 = expandFromCenter(s, i, i);
            // Even-length palindromes (center = between i and i+1)
            int l2 = expandFromCenter(s, i, i + 1);

            int len = max(l1, l2);
            if (len > maxLen) {
                maxLen = len;
                start = i - (len - 1) / 2;  // recompute left boundary
            }
        }

        return s.substr(start, maxLen);
    }

private:
    // Expands outward from (left, right) as long as chars match; returns length of palindrome
    int expandFromCenter(const string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;  // length of the palindrome found
    }
};