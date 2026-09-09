class Solution {
public:
    long long countCommas(long long n) {
        long long totalCommas = 0;
        long long threshold = 1000; // 10^3: numbers >= 1,000 have at least 1 comma

        while (n >= threshold) {
            totalCommas += (n - threshold + 1);
            
            // Prevent integer overflow before multiplying by 1000
            if (threshold > LLONG_MAX / 1000) break;
            threshold *= 1000;
        }

        return totalCommas;
    }
};