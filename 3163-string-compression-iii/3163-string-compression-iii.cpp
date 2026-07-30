class Solution {
public:
    string compressedString(string word) {
        string ans = "";
        int n = word.size();
        int i = 0;
        while (i < n) {
            char ch = word[i];
            int cnt = 0;
            while (i < n && word[i] == ch && cnt < 9) {
                cnt++;
                i++;
            }
            ans += to_string(cnt);
            ans += ch;
        }
        return ans;
    }
};