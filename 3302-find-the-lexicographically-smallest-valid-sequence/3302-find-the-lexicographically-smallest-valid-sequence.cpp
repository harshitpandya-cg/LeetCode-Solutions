class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> suf(m, -1);

        int p = n - 1;

        for (int j = m - 1; j >= 0; j--) {
            while (p >= 0 && word1[p] != word2[j]) {
                p--;
            }

            if (p < 0)
                break;

            suf[j] = p;
            p--;
        }

        vector<int> ans;
        int pos = 0;
        bool usedMismatch = false;

        for (int j = 0; j < m; j++) {
            while (pos < n) {
                if (word1[pos] == word2[j]) {
                    ans.push_back(pos);
                    pos++;
                    break;
                }

                if (!usedMismatch) {
                    if (j == m - 1) {
                        ans.push_back(pos);
                        pos++;
                        usedMismatch = true;
                        break;
                    }

                    if (suf[j + 1] != -1 && suf[j + 1] > pos) {
                        ans.push_back(pos);
                        pos++;
                        usedMismatch = true;
                        break;
                    }
                }

                pos++;
            }

            if (ans.size() != j + 1)
                return {};
        }

        return ans;
    }
};