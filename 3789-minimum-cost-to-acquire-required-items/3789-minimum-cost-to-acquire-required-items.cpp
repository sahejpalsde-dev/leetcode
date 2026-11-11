class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        auto f = [&](long long b) {                  // b = number of type-3 items bought
            return b * costBoth
                 + max(0LL, need1 - b) * cost1       // type-1 items still needed
                 + max(0LL, need2 - b) * cost2;      // type-2 items still needed
        };
        return min({f(0), f(need1), f(need2)});      // the minimum is at a breakpoint
    }
};