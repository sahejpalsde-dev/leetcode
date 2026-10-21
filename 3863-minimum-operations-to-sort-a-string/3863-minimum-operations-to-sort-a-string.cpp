class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        if (is_sorted(s.begin(), s.end())) return 0;   // already sorted
        if (n == 2) return -1;                         // only length-1 substrings allowed

        char mn = *min_element(s.begin(), s.end());
        char mx = *max_element(s.begin(), s.end());

        // sort s[1..n-1] or s[0..n-2]: the whole string becomes sorted
        if (s[0] == mn || s[n - 1] == mx) return 1;

        // the min is stuck alone at the end and the max is stuck alone at the front
        if (s[n - 1] == mn && count(s.begin(), s.end(), mn) == 1 &&
            s[0] == mx && count(s.begin(), s.end(), mx) == 1)
            return 3;

        return 2;
    }
};