class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> result(m);
        int i;
        switch (m * n == original.size() ? 1 : 0) {
            case 1:
                i = 0;
                while (i < m) {
                    result[i] = vector<int>(original.begin() + i * n, original.begin() + (i * n + n));
                    i++;
                }
                break;
            default:
                return {};
        }
        return result;
    }
};

static const auto kds = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
