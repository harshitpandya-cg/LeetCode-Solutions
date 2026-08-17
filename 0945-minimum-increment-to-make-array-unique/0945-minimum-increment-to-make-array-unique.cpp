class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int ans = 0;
        int next = 0;

        for (int x : nums) {
            if (x >= next) {
                next = x + 1;
            } else {
                ans += next - x;
                next++;
            }
        }

        return ans;
    }
};