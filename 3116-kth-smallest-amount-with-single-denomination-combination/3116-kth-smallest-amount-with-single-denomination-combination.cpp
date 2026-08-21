class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        long long low = 1;
        long long high = 1LL * (*min_element(coins.begin(), coins.end())) * k;

        auto lcm = [](long long a, long long b) {
            return a / std::gcd(a, b) * b;
        };

        auto count = [&](long long x) {
            long long ans = 0;
            int n = coins.size();

            for (int mask = 1; mask < (1 << n); mask++) {
                long long multiple = 1;
                int bits = 0;
                bool valid = true;

                for (int i = 0; i < n; i++) {
                    if (mask & (1 << i)) {
                        bits++;

                        multiple = lcm(multiple, coins[i]);

                        if (multiple > x) {
                            valid = false;
                            break;
                        }
                    }
                }

                if (!valid) continue;

                long long ways = x / multiple;

                if (bits % 2)
                    ans += ways;
                else
                    ans -= ways;
            }

            return ans;
        };

        while (low < high) {
            long long mid = low + (high - low) / 2;

            if (count(mid) >= k)
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};