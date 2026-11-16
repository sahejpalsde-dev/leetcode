class Solution {
public:
    string digitSum(string s, int k) {
        while ((int)s.size() > k) {                       // a round is possible only if length > k
            string next;
            for (int i = 0; i < (int)s.size(); i += k) {  // walk through the groups of size k
                int sum = 0;
                for (int j = i; j < min((int)s.size(), i + k); j++)
                    sum += s[j] - '0';                    // add up the digits in this group
                next += to_string(sum);                   // the group becomes its digit sum
            }
            s = next;                                     // merge the groups and repeat
        }
        return s;
    }
};