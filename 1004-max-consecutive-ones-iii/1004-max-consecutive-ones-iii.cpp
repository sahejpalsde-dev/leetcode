class Solution {
public:
    int longestOnes(vector<int>& arr, int k) {

        int ans = 0;
        int i = 0;
        int j = 0;
        int count = 0;
        int maxi = INT_MIN;

        while (j < arr.size()) {

            // If current element is 0
            if (arr[j] == 0)
                count++;

            // If zeros become more than k
            while (count > k) {

                if (arr[i] == 0)
                    count--;

                i++;
            }

            // Calculate current window length
            ans = j - i + 1;

            maxi = max(maxi, ans);

            j++;
        }

        return maxi;
    }
};