class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long min_result = LLONG_MAX;  // Start with a large number for the minimum score.
        long long row1_sum = accumulate(grid[0].begin(), grid[0].end(), 0LL);  // Top row sum
        long long row2_sum = 0;  // Bottom row sum starts at 0.

        for (int i = 0; i < grid[0].size(); ++i) {
            row1_sum -= grid[0][i];  // Move the top player forward, subtract current value.
            min_result = min(min_result, max(row1_sum, row2_sum));  // Update the minimum of the max scores.
            row2_sum += grid[1][i];  // Move the bottom player forward, add current value.
        }

        return min_result;  // Return the minimum maximum score.
    }
};