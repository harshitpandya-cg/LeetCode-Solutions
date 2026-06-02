class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> mp;

        for (int i = 1; i <= n; i++) {
            int num = i;
            int sum = 0;

            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }

            mp[sum]++;
        }

        int maxSize = 0;

        for (auto &p : mp) {
            maxSize = max(maxSize, p.second);
        }

        int ans = 0;

        for (auto &p : mp) {
            if (p.second == maxSize) {
                ans++;
            }
        }

        return ans;
    }
};