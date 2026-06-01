class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> bannedSet(banned.begin(), banned.end());
        unordered_map<string, int> freq;

        string word = "";

        for (char &c : paragraph) {
            if (isalpha(c)) {
                word += tolower(c);
            } else {
                if (!word.empty()) {
                    if (!bannedSet.count(word)) {
                        freq[word]++;
                    }
                    word.clear();
                }
            }
        }

        if (!word.empty() && !bannedSet.count(word)) {
            freq[word]++;
        }
        string result;
        int maxFreq = 0;
        for (auto &it : freq) {
            if (it.second > maxFreq) {
                maxFreq = it.second;
                result = it.first;
            }
        }

        return result;
    }
};