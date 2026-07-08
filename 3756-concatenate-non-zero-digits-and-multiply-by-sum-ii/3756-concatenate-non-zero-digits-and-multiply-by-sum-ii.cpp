class Solution {
public:
    const int MOD = 1000000007;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {

        int n = s.size();

        vector<int> pos;      // Positions of non-zero digits
        vector<int> digit;    // Non-zero digits

        for (int i = 0; i < n; i++) {
            if (s[i] != '0') {
                pos.push_back(i);
                digit.push_back(s[i] - '0');
            }
        }

        int m = digit.size();

        // power10[i] = 10^i % MOD
        vector<long long> power10(m + 1, 1);
        for (int i = 1; i <= m; i++) {
            power10[i] = (power10[i - 1] * 10) % MOD;
        }

        // Prefix concatenated number
        vector<long long> prefixNum(m + 1, 0);
        for (int i = 0; i < m; i++) {
            prefixNum[i + 1] = (prefixNum[i] * 10 + digit[i]) % MOD;
        }

        // Prefix sum of digits
        vector<long long> prefixSum(m + 1, 0);
        for (int i = 0; i < m; i++) {
            prefixSum[i + 1] = prefixSum[i] + digit[i];
        }

        vector<int> ans;

        for (auto &q : queries) {

            int l = q[0];
            int r = q[1];

            // First non-zero digit in range
            int left = lower_bound(pos.begin(), pos.end(), l) - pos.begin();

            // Last non-zero digit in range
            int right = upper_bound(pos.begin(), pos.end(), r) - pos.begin() - 1;

            if (left > right) {
                ans.push_back(0);
                continue;
            }

            int len = right - left + 1;

            long long number =
                (prefixNum[right + 1]
                - (prefixNum[left] * power10[len]) % MOD
                + MOD) % MOD;

            long long sum =
                prefixSum[right + 1] - prefixSum[left];

            ans.push_back((number * sum) % MOD);
        }

        return ans;
    }
};