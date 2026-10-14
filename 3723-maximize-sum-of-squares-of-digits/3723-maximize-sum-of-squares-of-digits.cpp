class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num) return "";            // even all 9s cannot reach the sum

        string ans;
        int rem = sum;
        for (int i = 0; i < num; i++) {
            int d = min(9, rem);                 // take as much as one digit allows
            ans.push_back('0' + d);
            rem -= d;
        }
        return ans;
    }
};