class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        unordered_map<int, int> rows;

        for (const auto& seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];

            rows[row] |= (1 << (col - 1));
        }

        int result = 2 * (n - rows.size());

        int left  = (1 << 1) | (1 << 2) | (1 << 3) | (1 << 4);
        int mid   = (1 << 3) | (1 << 4) | (1 << 5) | (1 << 6);
        int right = (1 << 5) | (1 << 6) | (1 << 7) | (1 << 8);

        for (const auto& [row, mask] : rows) {

            bool canLeft  = !(mask & left);
            bool canMid   = !(mask & mid);
            bool canRight = !(mask & right);

            if (canLeft && canRight) {
                result += 2;
            }
            else if (canLeft || canMid || canRight) {
                result += 1;
            }
        }

        return result;
    }
};