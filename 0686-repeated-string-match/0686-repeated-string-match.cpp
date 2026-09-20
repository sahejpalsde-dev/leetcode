class Solution {
public:

    bool check(string str3, string b) {

        int n = b.size();

        // Build LPS for b
        vector<int> lps(n, 0);

        int prev = 0;
        int suff = 1;

        while (suff < n) {

            if (b[prev] == b[suff]) {
                lps[suff] = prev + 1;
                prev++;
                suff++;
            }
            else {
                if (prev == 0) {
                    lps[suff] = 0;
                    suff++;
                }
                else {
                    prev = lps[prev - 1];
                }
            }
        }

        // Search b inside str3 using KMP
        int i = 0;
        int j = 0;

        while (i < str3.size()) {

            if (str3[i] == b[j]) {
                i++;
                j++;
            }

            if (j == b.size()) {
                return true;
            }

            if (i < str3.size() && str3[i] != b[j]) {

                if (j == 0) {
                    i++;
                }
                else {
                    j = lps[j - 1];
                }
            }
        }

        return false;
    }

    int repeatedStringMatch(string a, string b) {

        string str3 = a;
        int count = 1;

        // Repeat a until its length becomes >= b
        while (str3.size() < b.size()) {
            str3 = str3 + a;
            count++;
        }

        // Check first
        if (check(str3, b)) {
            return count;
        }

        // Sometimes one extra repetition is required
        str3 = str3 + a;
        count++;

        if (check(str3, b)) {
            return count;
        }

        return -1;
    }
};