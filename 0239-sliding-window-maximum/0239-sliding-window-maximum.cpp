/*class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
    }
};    
*/

#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> arr;
        deque<int> dq;

        for (int i = 0; i < n; i++) {

            // Remove indices that are outside the current window
            while (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // Remove smaller elements from the back
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);

            // Start storing answers once the first window is complete
            if (i >= k - 1) {
                arr.push_back(nums[dq.front()]);
            }
        }

        return arr;
    }
};
