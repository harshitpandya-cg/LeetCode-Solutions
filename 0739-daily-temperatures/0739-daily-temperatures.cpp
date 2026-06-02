class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            int j = i + 1;
            while (j < n) {
                if (temperatures[j] > temperatures[i]) {
                    ans[i] = j - i;
                    break;
                }
                if (ans[j] == 0) break; 
                j = j + ans[j]; 
            }
        }

        return ans;
    }
};