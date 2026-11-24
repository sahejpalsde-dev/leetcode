
class Solution {
public:

    void solve(int k, int n, int idx,
               vector<int>& arr,
               vector<int>& temp,
               vector<vector<int>>& ans) {

        // Base case
        if (n == 0 && k == 0) {
            ans.push_back(temp);
            return;
        }

        // Invalid condition
        if (n < 0 || k < 0 || idx == arr.size()) {
            return;
        }

        // NOT PICK
        solve(k, n, idx + 1, arr, temp, ans);

        // PICK
        temp.push_back(arr[idx]);

        solve(k - 1, n - arr[idx], idx + 1, arr, temp, ans);

        // Backtracking
        temp.pop_back();
    }

    vector<vector<int>> combinationSum3(int k, int n) {

        vector<int> arr = {1,2,3,4,5,6,7,8,9};

        vector<int> temp;
        vector<vector<int>> ans;

        solve(k, n, 0, arr, temp, ans);

        return ans;
    }
};
