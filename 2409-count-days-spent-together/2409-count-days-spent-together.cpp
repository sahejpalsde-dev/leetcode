class Solution {
    int toDay(const string& d) {                          // "MM-DD" -> day of the year
        static const int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int m = stoi(d.substr(0, 2));
        int res = stoi(d.substr(3, 2));
        for (int i = 0; i < m - 1; i++) res += days[i];   // add the full months before m
        return res;
    }

public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int start = max(toDay(arriveAlice), toDay(arriveBob));   // later arrival
        int end   = min(toDay(leaveAlice),  toDay(leaveBob));    // earlier departure
        return max(0, end - start + 1);                          // 0 if they never overlap
    }
};