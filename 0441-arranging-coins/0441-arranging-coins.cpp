class Solution {
public:
    int arrangeCoins(int n) {
        long long sum = 0;
        int rows = 0;

        while (sum + rows + 1 <= n) {
            rows++;
            sum += rows;
        }

        return rows;
    }
};