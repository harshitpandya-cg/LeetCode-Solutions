class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l1 = nums[n - 1];
        int l2 = nums[n - 2];
        int s1 = nums[0];
        int s2 = nums[1];
        return (l1 * l2) - (s1 * s2);
    }
};