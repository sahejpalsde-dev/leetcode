class Solution {
public:
    int distinctSubseqII(string s) {
        long long last[26] = {0};
        long long totalSum = 0;
        int MOD = 1e9 + 7;

        for (char c : s) {
            int idx = c - 'a';
            
            // New distinct subsequences ending with character 'c'
            long long newCount = (totalSum + 1) % MOD;
            
            // Update totalSum: add newCount and remove previous last[idx] count
            totalSum = (totalSum + newCount - last[idx] + MOD) % MOD;
            
            // Store the updated count for character 'c'
            last[idx] = newCount;
        }

        return totalSum;
    }
};