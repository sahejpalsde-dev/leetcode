class Solution {
public:
    string longestPrefix(string s) {

        // Step 1: Make LPS array
        int n = s.size();
        vector<int> lps(n, 0);

        int len = 0;
        int i = 1;

        while (i < n) {

            if (s[i] == s[len]) {
                len++;
                lps[i] = len;
                i++;
            }
            else {
                if (len != 0) {
                    len = lps[len - 1];
                }
                else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        // Step 2: Get the length of longest happy prefix
        int index = lps[n - 1];

        // Step 3: Store characters in new string
        string ans = "";

        for (int i = 0; i < index; i++) {
            ans += s[i];
        }

        return ans;
    }
};