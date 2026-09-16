class Solution {
public:
    static const long long MOD = 1e9 + 7;

    long long modPow(long long a, long long e) {
        long long res = 1;

        while (e) {
            if (e & 1)
                res = res * a % MOD;

            a = a * a % MOD;
            e >>= 1;
        }

        return res;
    }

    int numberOfSets(int n, int k) {
        int N = n + k - 1;

        vector<long long> fact(N + 1), invFact(N + 1);

        fact[0] = 1;
        for (int i = 1; i <= N; i++)
            fact[i] = fact[i - 1] * i % MOD;

        invFact[N] = modPow(fact[N], MOD - 2);

        for (int i = N; i >= 1; i--)
            invFact[i - 1] = invFact[i] * i % MOD;

        long long ans = fact[N];

        ans = ans * invFact[2 * k] % MOD;
        ans = ans * invFact[N - 2 * k] % MOD;

        return ans;
    }
};