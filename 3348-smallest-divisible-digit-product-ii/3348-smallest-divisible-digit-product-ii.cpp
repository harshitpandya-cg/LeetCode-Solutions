class Solution {
public:

    int factor[10][4] = {
        {0, 0, 0, 0}, // 0
        {0, 0, 0, 0}, // 1
        {1, 0, 0, 0}, // 2
        {0, 1, 0, 0}, // 3
        {2, 0, 0, 0}, // 4
        {0, 0, 1, 0}, // 5
        {1, 1, 0, 0}, // 6
        {0, 0, 0, 1}, // 7
        {3, 0, 0, 0}, // 8
        {0, 2, 0, 0}  // 9
    };

    int min23[50][50];

    int minDigits(int a, int b, int c, int d) {

        if (a < 0 || b < 0 || c < 0 || d < 0)
            return 1e9;

        return min23[a][b] + c + d;
    }

    string buildSuffix(int len, int a, int b, int c, int d) {

        string ans;

        for (int pos = 0; pos < len; pos++) {

            int remaining = len - pos - 1;

            for (int digit = 1; digit <= 9; digit++) {

                int na = max(0, a - factor[digit][0]);
                int nb = max(0, b - factor[digit][1]);
                int nc = max(0, c - factor[digit][2]);
                int nd = max(0, d - factor[digit][3]);

                if (minDigits(na, nb, nc, nd) <= remaining) {

                    ans += char('0' + digit);

                    a = na;
                    b = nb;
                    c = nc;
                    d = nd;

                    break;
                }
            }
        }

        return ans;
    }

    string smallestNumber(string num, long long t) {

        // ------------------------------------------------
        // 1. Factorize t
        // ------------------------------------------------

        int target[4] = {0, 0, 0, 0};

        long long x = t;

        int primes[4] = {2, 3, 5, 7};

        for (int i = 0; i < 4; i++) {

            while (x % primes[i] == 0) {
                target[i]++;
                x /= primes[i];
            }
        }

        // t contains a prime other than 2,3,5,7
        if (x != 1)
            return "-1";


        // ------------------------------------------------
        // 2. Precompute minimum digits for 2^a * 3^b
        // ------------------------------------------------

        for (int a = 0; a < 50; a++) {

            for (int b = 0; b < 50; b++) {

                min23[a][b] = 1e9;

                for (int six = 0; six <= min(a, b); six++) {

                    int aa = a - six;
                    int bb = b - six;

                    // Use 8 = 2^3
                    int cost2 = (aa + 2) / 3;

                    // Use 9 = 3^2
                    int cost3 = (bb + 1) / 2;

                    int total = six + cost2 + cost3;

                    min23[a][b] =
                        min(min23[a][b], total);
                }
            }
        }


        // ------------------------------------------------
        // 3. Count prime factors in num
        // ------------------------------------------------

        int have[4] = {0, 0, 0, 0};

        int firstZero = -1;

        for (int i = 0; i < num.size(); i++) {

            int digit = num[i] - '0';

            if (digit == 0) {

                if (firstZero == -1)
                    firstZero = i;

                continue;
            }

            for (int j = 0; j < 4; j++) {
                have[j] += factor[digit][j];
            }
        }


        // ------------------------------------------------
        // 4. num itself already works
        // ------------------------------------------------

        if (firstZero == -1) {

            bool ok = true;

            for (int j = 0; j < 4; j++) {

                if (have[j] < target[j]) {
                    ok = false;
                    break;
                }
            }

            if (ok)
                return num;
        }


        // ------------------------------------------------
        // 5. Try to make same-length answer
        // ------------------------------------------------

        int prefix[4];

        for (int j = 0; j < 4; j++)
            prefix[j] = have[j];

        int n = num.size();

        for (int i = n - 1; i >= 0; i--) {

            int oldDigit = num[i] - '0';

            // Remove current digit from prefix
            if (oldDigit != 0) {

                for (int j = 0; j < 4; j++) {
                    prefix[j] -= factor[oldDigit][j];
                }
            }


            // ------------------------------------------------
            // IMPORTANT FIX:
            //
            // If i is AFTER the first zero, we cannot change
            // this position because the zero would remain in
            // the prefix.
            // ------------------------------------------------

            if (firstZero != -1 && i > firstZero)
                continue;

            for (int newDigit = oldDigit + 1;
                 newDigit <= 9;
                 newDigit++) {

                int need[4];

                for (int j = 0; j < 4; j++) {

                    need[j] = max(
                        0,
                        target[j]
                        - prefix[j]
                        - factor[newDigit][j]
                    );
                }

                int suffixLength = n - i - 1;

                if (minDigits(
                        need[0],
                        need[1],
                        need[2],
                        need[3]
                    ) <= suffixLength) {

                    string ans = num.substr(0, i);

                    ans += char('0' + newDigit);

                    ans += buildSuffix(
                        suffixLength,
                        need[0],
                        need[1],
                        need[2],
                        need[3]
                    );

                    return ans;
                }
            }
        }

        int requiredDigits = minDigits(
            target[0],
            target[1],
            target[2],
            target[3]
        );

        if (requiredDigits == 1e9)
            return "-1";

        int len = max(n + 1, requiredDigits);

        return buildSuffix(
            len,
            target[0],
            target[1],
            target[2],
            target[3]
        );
    }
};