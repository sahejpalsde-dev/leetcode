class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        // Step 1: Count available digit frequencies
        vector<int> freq(10, 0);
        for (int d : digits) {
            freq[d]++;
        }

        int count = 0;

        // Step 2: Check all candidate 3-digit even numbers (100 to 998)
        for (int num = 100; num <= 998; num += 2) {
            int d1 = num / 100;       // Hundreds place
            int d2 = (num / 10) % 10; // Tens place
            int d3 = num % 10;        // Units place

            vector<int> currentFreq(10, 0);
            currentFreq[d1]++;
            currentFreq[d2]++;
            currentFreq[d3]++;

            // Step 3: Check if input has enough copies of required digits
            bool possible = true;
            for (int d = 0; d < 10; d++) {
                if (currentFreq[d] > freq[d]) {
                    possible = false;
                    break;
                }
            }

            if (possible) {
                count++;
            }
        }

        return count;
    }
};