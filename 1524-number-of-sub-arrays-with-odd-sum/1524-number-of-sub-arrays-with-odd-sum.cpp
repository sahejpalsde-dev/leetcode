class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        long long even = 1, odd = 0;      // counts of prefixes (including the empty one) with even / odd sum
        int parity = 0;                   // parity of the current prefix sum
        long long ans = 0;

        for (int x : arr) {
            parity ^= (x & 1);
            if (parity) {                 // prefix is odd: pair it with every earlier even prefix
                ans += even;
                odd++;
            } else {                      // prefix is even: pair it with every earlier odd prefix
                ans += odd;
                even++;
            }
            ans %= MOD;
        }
        return (int)ans;
    }
};