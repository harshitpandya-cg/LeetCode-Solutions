class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, set<int>> mp;
        for (auto &seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];

            if (col >= 2 && col <= 9) {
                mp[row].insert(col);
            }
        }
        int ans = (n - mp.size()) * 2;
        for (auto &it : mp) {
            set<int> &s = it.second;
            bool left = true;
            bool middle = true;
            bool right = true;
            for (int col = 2; col <= 5; col++) {
                if (s.count(col)) {
                    left = false;
                    break;
                }
            }
            for (int col = 4; col <= 7; col++) {
                if (s.count(col)) {
                    middle = false;
                    break;
                }
            }
            for (int col = 6; col <= 9; col++) {
                if (s.count(col)) {
                    right = false;
                    break;
                }
            }
            if (left && right)
                ans += 2;
            else if (left || middle || right)
                ans += 1;
        }

        return ans;
    }
};