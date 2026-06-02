class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int lines = 1;
        int width = 0;

        for (char ch : s) {
            int w = widths[ch - 'a'];

            if (width + w > 100) {
                lines++;
                width = w;
            } else {
                width += w;
            }
        }

        return {lines, width};
    }
};